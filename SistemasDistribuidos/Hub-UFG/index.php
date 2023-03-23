<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HUB UFG</title>
    <link rel="icon" type="image/x-icon" href="./src/img/ufg-icon.png">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="./src/css/style.css">
</head>
<body>
    
    <div class="formulario-envio-email">

        <img src="./src/img/ufg-icon.png" class="img-email-form">

        <form class="form-envio-email" action="../application/registra_assinante.php" method="post" enctype="multipart/form-data">
            <label for="inputEmail3">Informe o seu e-mail</label>
            <input type="email" class="form-control" id="inputEmail3" placeholder="E-mail" name="email_assinante" required>
            <div class="form-check">
            <input class="form-check-input" type="checkbox" id="gridCheck1" required>
            <label class="form-check-label" for="gridCheck1">
                Concordo em receber e-mails informativos de HUB UFG.
            </label>
            </div>
            <div class="link-curador-login">
                <a href="./home/curador.php">Sou um Administrador</a>
            </div>
            
            <button type="submit" class="btn btn-primary button-email">Enviar</button>
        </form>

    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>
</html>