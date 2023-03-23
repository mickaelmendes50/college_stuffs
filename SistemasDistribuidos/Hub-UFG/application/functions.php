<?php

use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;

require './src/Libraries/PHPMailer/src/Exception.php';
require './src/Libraries/PHPMailer/src/PHPMailer.php';
require './src/Libraries/PHPMailer/src/SMTP.php';

function validaSessao(){

    session_start();

    //Setando as variáveis que computam o tempo de sessão;
    $tempo = $_SERVER['REQUEST_TIME'];
    $duracao = 3600;

    if(isset($_SESSION['LAST_ACTIVITY']) && ($tempo - $_SESSION['LAST_ACTIVITY']) > $duracao){

        session_unset();
        session_destroy();
        header('location:../home/curador.php');

    }

    $_SESSION['LAST_ACTIVITY'] = $tempo;
    
}

function valida_usuario($login_curador, $senha_curador){

    $server = 'localhost';
    $login = 'hubufg';
    $senha = 'Asdbdh5fd1!';
    $nome_banco = 'hubufg';

    //Cria conexão com o banco;

    $conn = new mysqli($server, $login, $senha, $nome_banco);
    if($conn->connect_error){

        die("Connection failed: ".$conn->connect_error);

    }

    $login_curador = stripcslashes($login_curador);
    $senha_curador = stripcslashes($senha_curador);
    $login_curador = mysqli_real_escape_string($conn, $login_curador);
    $senha_curador = mysqli_real_escape_string($conn, $senha_curador);

    //Consulta;

    $sql = "SELECT * FROM hubufg.usuarios WHERE email = '$login_curador';";
    $runQuery = $conn->query($sql);
    $registro_usuario = mysqli_fetch_array($runQuery);

    if(isset($registro_usuario)){

        $valida_senha = password_verify($senha_curador, $registro_usuario['senha']);
        if($registro_usuario['email'] == $login_curador && $valida_senha){

            $_SESSION['login'] = $registro_usuario['email'];
            $_SESSION['senha'] = $registro_usuario['senha'];
            header('location:../home/main.php');

        }else{

            unset($_SESSION['login']);
            unset($_SESSION['senha']);
            header('Set-Cookie: usuario_logado=false; expires=30; path=/');
            header('location:../home/curador.php');

        }

    }else{

        unset($_SESSION['login']);
        unset($_SESSION['senha']);
        header('Set-Cookie: usuario_logado=false; expires=30; path=/');
        header('location:../home/curador.php');

    }

}

function cadastra_novo_usuario($login_hubufg, $senha_hubufg){

    $server = 'localhost';
    $login = 'hubufg';
    $senha = 'Asdbdh5fd1!';
    $nome_banco = 'hubufg';

    $conn = new mysqli($server, $login, $senha, $nome_banco);
    if($conn->connect_error){

        die("Connection failed: ".$conn->connect_error);

    }  

    $login_hubufg = stripcslashes($login_hubufg);
    $senha_hubufg = stripcslashes($senha_hubufg);
    $login_hubufg = mysqli_real_escape_string($conn, $login_hubufg);
    $senha_hubufg = mysqli_real_escape_string($conn, $senha_hubufg);

    $senha_encriptada = password_hash($senha_hubufg, PASSWORD_DEFAULT);

    $sql_consulta = "SELECT * FROM hubufg.usuarios WHERE email = '$login_hubufg';";
    $runQuery = $conn->query($sql_consulta);

    if($runQuery === false || $runQuery->num_rows == 0){

        $sql = "INSERT INTO hubufg.usuarios(email, senha) VALUES('$login_hubufg', '$senha_encriptada');";
        $runQuery = $conn->query($sql);

    }else{

        $sql = "UPDATE hubufg.usuarios SET senha = '$senha_encriptada' WHERE email = '$login_hubufg';";
        $runQuery = $conn->query($sql);

    }

    return $runQuery;

}

function recupera_enderecos(){

    $server = 'localhost';
    $login = 'hubufg';
    $senha = 'Asdbdh5fd1!';
    $nome_banco = 'hubufg';

    $conn = new mysqli($server, $login, $senha, $nome_banco);
    if($conn->connect_error){

        die("Connection failed: ".$conn->connect_error);

    }  

    $sql_consulta = "SELECT * FROM hubufg.email_list;";
    $runQuery = $conn->query($sql_consulta);

    if($runQuery === false || $runQuery->num_rows == 0){

        return false;

    }

    $array_emails = mysqli_fetch_all($runQuery, MYSQLI_ASSOC);

    return $array_emails;

}

function registra_assinante($email){

    $server = 'localhost';
    $login = 'hubufg';
    $senha = 'Asdbdh5fd1!';
    $nome_banco = 'hubufg';

    $conn = new mysqli($server, $login, $senha, $nome_banco);
    if($conn->connect_error){

        die("Connection failed: ".$conn->connect_error);

    }  

    $sql_consulta = "SELECT * FROM hubufg.email_list WHERE email = '$email';";
    $runQuery = $conn->query($sql_consulta);

    if($runQuery === false || $runQuery->num_rows == 0){

        $sql = "INSERT INTO hubufg.email_list(email) VALUES('$email');";
        $runQuery = $conn->query($sql);

    }else{

        $runQuery = (bool) false;

    }

    return $runQuery;

}

function enviar_email($enderecos, $assunto, $corpo){

    // Importe a biblioteca PHPMailer

    // Crie uma nova instância do PHPMailer
    $mail = new PHPMailer;

    // Defina as configurações do servidor SMTP do Google
    $mail->isSMTP();
    $mail->Host = 'smtp.gmail.com';
    $mail->SMTPAuth = true;
    $mail->Username = 'hubufg@gmail.com';
    $mail->Password = 'nhjzyjoxlpefajlu';
    $mail->SMTPSecure = 'tls';
    $mail->Port = 587;

    // Defina o remetente e o destinatário do e-mail
    $mail->setFrom($mail->Username, 'HUB UFG');

    // Defina o assunto e o corpo do e-mail
    $mail->Subject = $assunto;
    $mail->Body    = $corpo;

    //Adiciona o e-mail principal;
    $mail->addAddress('hubufg@gmail.com', 'HUB UFG');

    if(isset($enderecos)){

        $qtd_email = count($enderecos);

    }else{

        $qtd_email = 0;
        
    }

    for($i = 0; $i < $qtd_email; $i++){

        $email_usuario = $enderecos[$i]['email'];
        
        $mail->addBcc($email_usuario, $email_usuario);

    }

    // Envie o e-mail e verifique se houve erros
    if(!$mail->send()) {
        echo 'Erro ao enviar o e-mail: ' . $mail->ErrorInfo;
    } else {
        echo 'E-mail enviado com sucesso!!!';
    }

}

?>