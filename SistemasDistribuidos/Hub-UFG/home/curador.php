<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HUB UFG</title>
    <link rel="icon" type="image/x-icon" href="../src/img/ufg-icon.png">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="../src/css/style.css">
</head>
<body>

    <?php

        if(isset($_COOKIE['usuario_logado']) && $_COOKIE['usuario_logado'] == 'false'){

            echo    '<div class="alert alert-danger mensagem-pos-acao">
                        <strong>Erro:</strong> Usuário e/ou senha incorreto(s)!!!
                    </div>';
            unset($_COOKIE['usuario_logado']);
            header('Set-Cookie: usuario_logado= ; expires=0; path=/');
                        
        }

    ?>

    <div class="formulario-login">

        <img src="../src/img/ufg-icon.png" class="img-email-form">

        <form class="form-login" action="../application/authentication.php" method="post">
            <div class="campo-email">
                <label for="inputEmail3">Email</label>
                <input type="email" class="form-control" id="inputEmail3" placeholder="E-mail" name="curador_login" required>
            </div>
            <div class="campo-senha">
                <label for="inputPassword3" class="col-sm-2 col-form-label">Senha</label>
                <input type="password" class="form-control" id="inputPassword3" placeholder="Senha" name="curador_senha" required>
            </div>

            
            <button type="submit" class="btn btn-primary button-login">Enviar</button>
        </form>

    </div>
    

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>
</html>