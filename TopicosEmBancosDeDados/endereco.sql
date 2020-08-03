CREATE TABLE UF(
    Sigla_UF CHARACTER VARYING(2) NOT NULL,
    Nome_UF CHARACTER VARYING(20) NOT NULL,

    CONSTRAINT PrkUF PRIMARY KEY (Sigla_UF),     
);

CREATE TABLE MUNICIPIO(
    Codigo_Municipio INTEGER NOT NULL,
    Nome_Municipio CHARACTER VARYING(80) NOT NULL,
    Sigla_UF CHARACTER VARYING(2) NOT NULL,
    
    CONSTRAINT PrkMunicipio PRIMARY KEY (Codigo_Municipio),
    CONSTRAINT FrkUfMunicipio FOREIGN KEY (Sigla_UF) REFERENCES UF (Sigla_UF),
);

CREATE TABLE BAIRRO(
    Codigo_Bairro INTEGER NOT NULL,
    Nome_Bairro CHARACTER VARYING(80) NOT NULL,
    Codigo_Municipio INTEGER NOT NULL,

    CONSTRAINT PrkBairro PRIMARY KEY (Codigo_Bairro),
    CONSTRAINT FrkMunicipioBairro FOREIGN KEY (Codigo_Municipio) REFERENCES MUNICIPIO (Codigo_Municipio),
);

CREATE TABLE LOGRADOURO(
    Codigo_Logradouro INTEGER NOT NULL,
    Nome_Logradouro CHARACTER VARYING(80) NOT NULL,
    CEP CHARACTER VARYING(8) NOT NULL,
    Codigo_Bairro INTEGER NOT NULL,

    CONSTRAINT PrkLogradouro PRIMARY KEY (Codigo_Logradouro),
    CONSTRAINT FrkBairroLogradouro FOREIGN KEY (Codigo_Bairro) REFERENCES BAIRRO (Codigo_Bairro),
);

CREATE TABLE ENDERECO(
    Id_Endereco INTEGER NOT NULL,
    Quadra CHARACTER VARYING(20) NOT NULL,
    Lote CHARACTER VARYING(20) NOT NULL,
    Numero CHARACTER VARYING(20) NOT NULL,
    Complemento CHARACTER VARYING(255) NOT NULL,
    Codigo_Logradouro INTEGER NOT NULL,

    CONSTRAINT PrkEndereco PRIMARY KEY (Id_Endereco),
    CONSTRAINT FrkLogradouroEndereco FOREIGN KEY (Codigo_Logradouro) REFERENCES LOGRADOURO (Codigo_Logradouro),
);

CREATE TABLE TELEFONE(
    Id_Endereco INTEGER NOT NULL,
    Telefone CHARACTER VARYING(20) NOT NULL,

    CONSTRAINT PrkTelefone PRIMARY KEY (Telefone, Id_Endereco),
    CONSTRAINT FrkEnderecoTelefone FOREIGN KEY (Id_Endereco) REFERENCES ENDERECO (Id_Endereco),
);

CREATE TABLE PESSOA(
    cpf CHARACTER VARYING(11) NOT NULL,
    nome CHARACTER VARYING(80) NOT NULL,
    nome_pai CHARACTER VARYING(80),
    nome_mae CHARACTER VARYING(80) NOT NULL,
    data_nascimento DATE NOT NULL,

    CONSTRAINT PrkPessoa PRIMARY KEY (cpf),
);

CREATE TABLE TIPODEENDERECO(
    Codigo_Tipo_End INTEGER NOT NULL,
    Nome_Tipo_End CHARACTER VARYING(20) NOT NULL,

    CONSTRAINT PrkTipoDeEndereco PRIMARY KEY (Codigo_Tipo_End),
);

CREATE TABLE POSSUI(
    cpf CHARACTER VARYING(11) NOT NULL,
    Id_Endereco INTEGER NOT NULL,
    Codigo_Tipo_End INTEGER NOT NULL,

    CONSTRAINT PrkPossui PRIMARY KEY (cpf, Id_Endereco),
    CONSTRAINT FrkPessoaPossui FOREIGN KEY (cpf) REFERENCES PESSOA (cpf),
    CONSTRAINT FrkEnderecoPossui FOREIGN KEY (Id_Endereco) REFERENCES ENDERECO (Id_Endereco),
    CONSTRAINT FrkTipoDeEnderecoPossui FOREIGN KEY (Codigo_Tipo_End) REFERENCES TIPODEENDERECO (Codigo_Tipo_End),
);

CREATE TABLE DEPENDENTE(
    Nome_Dependente CHARACTER VARYING(80) NOT NULL,
    data_nascimento DATE NOT NULL,
    Tipo_Dependente CHARACTER VARYING(20) NOT NULL,
    cpf CHARACTER VARYING(11) NOT NULL,

    CONSTRAINT PrkDependente PRIMARY KEY (Nome_Dependente, data_nascimento, Tipo_Dependente, cpf),
    CONSTRAINT FrkPessoaDependente FOREIGN KEY (cpf) REFERENCES PESSOA (cpf),
);