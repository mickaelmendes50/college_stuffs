<?php

    require('functions.php');

    validaSessao();

    $assunto = $_POST['assunto_email'];
    $corpo = $_POST['corpo_email'];
    $enderecos = recupera_enderecos();

    $assunto = utf8_decode($assunto);
    $corpo = utf8_decode($corpo);

    $envio = enviar_email($enderecos, $assunto, $corpo);

    $_SESSION['envio_email'] = $envio;
    header('location:../home/main.php');

?>