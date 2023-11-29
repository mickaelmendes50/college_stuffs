---------------------------------
-- Aluno: Mickael Mendes Mesquita
-- Matrícula: 201900967
---------------------------------
-- Prova 1 - Implementação
---------------------------------

-- 1.a)
-- Cria o banco de dados
CREATE DATABASE comercial;

-- Cria as tabelas
CREATE TABLE cliente (
    codigo INT PRIMARY KEY,
    nome VARCHAR(100),
    sexo CHAR(1)
);

CREATE TABLE produto (
    codigo INT PRIMARY KEY,
    nome VARCHAR(100),
    unidade VARCHAR(50),
    preco DECIMAL(10, 2)
);

CREATE TABLE pedido (
    numero INT PRIMARY KEY,
    data DATE,
    codcli INT,
    total DECIMAL(10, 2),
    FOREIGN KEY (codcli) REFERENCES cliente(codigo)
);

CREATE TABLE itempedido (
    numero INT,
    codpro INT,
    qtde INT,
    valor DECIMAL(10, 2),
    FOREIGN KEY (numero) REFERENCES pedido(numero),
    FOREIGN KEY (codpro) REFERENCES produto(codigo),
    PRIMARY KEY (numero, codpro)
);

--------------------------------------------------------
-- 1.b)
-- Cria a função que calcula o total do pedido:
CREATE OR REPLACE FUNCTION atualizar_total_pedido_function()
RETURNS TRIGGER AS $$
DECLARE
    total_pedido DECIMAL(10, 2);
BEGIN

    SELECT SUM(ip.qtde * ip.valor) INTO total_pedido
    FROM itempedido ip
    WHERE ip.numero = NEW.numero;

    UPDATE pedido
    SET total = total_pedido
    WHERE numero = NEW.numero;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

-- Cria a trigger pra chamar a função
CREATE TRIGGER atualizar_total_pedido_trigger
AFTER INSERT OR UPDATE OR DELETE ON itempedido
FOR EACH ROW
EXECUTE FUNCTION atualizar_total_pedido_function();

--------------------------------------------------------------------
-- 1.c)
SELECT c.nome AS nome_cliente, c.sexo AS sexo_cliente, 
       p.numero AS numero_pedido, p.data AS data_pedido,
       pr.nome AS nome_produto
FROM cliente c
INNER JOIN pedido p ON c.codigo = p.codcli
INNER JOIN itempedido ip ON p.numero = ip.numero
INNER JOIN produto pr ON ip.codpro = pr.codigo;

--------------------------------------------------------------------
-- 1.d)
SELECT  p.numero AS numero_pedido, p.data AS data_pedido, 
        c.nome AS nome_cliente, p.total AS valor_pedido
FROM pedido p
INNER JOIN cliente c ON p.codcli = c.codigo
WHERE p.total = (
    SELECT MAX(total) 
    FROM pedido
);

--------------------------------------------------------------------
-- 1.e)
SELECT ip.codpro AS codigo_produto, 
       pr.nome AS nome_produto, 
       SUM(ip.qtde) AS quantidade_vendida
FROM itempedido ip
INNER JOIN produto pr ON ip.codpro = pr.codigo
GROUP BY ip.codpro, pr.nome
ORDER BY quantidade_vendida DESC
LIMIT 1;

--------------------------------------------------------------------
-- 2.a)
CREATE TABLE auditoria (
    nome_tabela VARCHAR(20),
    acao VARCHAR(20),
    data_hora TIMESTAMP
);

--------------------------------------------------------------------
-- 2.b)
-- Cria as funções de auditoria:
CREATE OR REPLACE FUNCTION auditoria_cliente()
RETURNS TRIGGER AS $$
BEGIN
    IF (TG_OP = 'DELETE') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('cliente', 'DELETE', NOW());
    ELSIF (TG_OP = 'INSERT') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('cliente', 'INSERT', NOW());
    ELSIF (TG_OP = 'UPDATE') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('cliente', 'UPDATE', NOW());
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION auditoria_produto()
RETURNS TRIGGER AS $$
BEGIN
    IF (TG_OP = 'DELETE') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('produto', 'DELETE', NOW());
    ELSIF (TG_OP = 'INSERT') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('produto', 'INSERT', NOW());
    ELSIF (TG_OP = 'UPDATE') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('produto', 'UPDATE', NOW());
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION auditoria_pedido()
RETURNS TRIGGER AS $$
BEGIN
    IF (TG_OP = 'DELETE') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('pedido', 'DELETE', NOW());
    ELSIF (TG_OP = 'INSERT') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('pedido', 'INSERT', NOW());
    ELSIF (TG_OP = 'UPDATE') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('pedido', 'UPDATE', NOW());
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION auditoria_itempedido()
RETURNS TRIGGER AS $$
BEGIN
    IF (TG_OP = 'DELETE') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('itempedido', 'DELETE', NOW());
    ELSIF (TG_OP = 'INSERT') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('itempedido', 'INSERT', NOW());
    ELSIF (TG_OP = 'UPDATE') THEN
        INSERT INTO auditoria (nome_tabela, acao, data_hora)
        VALUES ('itempedido', 'UPDATE', NOW());
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

-- Cria as triggers para as funções de auditoria:
CREATE TRIGGER trigger_auditoria_cliente
AFTER INSERT OR UPDATE OR DELETE ON cliente
FOR EACH ROW EXECUTE FUNCTION auditoria_cliente();

CREATE TRIGGER trigger_auditoria_produto
AFTER INSERT OR UPDATE OR DELETE ON produto
FOR EACH ROW EXECUTE FUNCTION auditoria_produto();

CREATE TRIGGER trigger_auditoria_pedido
AFTER INSERT OR UPDATE OR DELETE ON pedido
FOR EACH ROW EXECUTE FUNCTION auditoria_pedido();

CREATE TRIGGER trigger_auditoria_itempedido
AFTER INSERT OR UPDATE OR DELETE ON itempedido
FOR EACH ROW EXECUTE FUNCTION auditoria_itempedido();
