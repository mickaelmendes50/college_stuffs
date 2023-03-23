<?php

	require('./application/functions.php');
	validaSessao();

?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HUB UFG - Main</title>
    <link rel="icon" type="image/x-icon" href="../src/img/ufg-icon.png">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="../src/css/style.css">
</head>
<body>
	
	<?php

	if(isset($_SESSION['envio_email']) && $_SESSION['envio_email'] == false){

		echo    '<div class="alert alert-danger mensagem-pos-acao">
					<strong>Erro:</strong> Erro ao enviar e-mail!!!
				</div>';
				
		unset($_SESSION['envio_email']);
					
	}

	?>

	<div class="area_trabalho_curador">
		<img src="../src/img/ufg-icon.png" class="img_curador">
		
		<div class="formulario_curador">
			<form action="../application/envia_email.php" method="post" enctype="multipart/form-data">
			  <div class="form-group">
				<label for="exampleFormControlInput1">Assunto</label>
				<input class="form-control" type="text" placeholder="Assunto do E-mail" name="assunto_email">
			  </div>
			  <div class="form-group">
				<label for="exampleFormControlTextarea1">Corpo do E-mail</label>
				<textarea class="form-control" id="exampleFormControlTextarea1" rows="3" name="corpo_email" placeholder="Insira o Corpo do Email"></textarea>
			  </div>
			  <button type="submit" class="btn btn-primary botao_envio_email">Enviar Newsletter</button>
			</form>
		</div>
	</div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>
</html>