<?php
include ('user.php');
unset($_SESSION['message']);
if (isset($_POST['submit']) && $_POST['submit'] == "Reinitialiser")
{
	if ($_POST['email'] == "")
		$_SESSION['message'] = "Veuillez renseigner une adresse email";
    else if (reinit_pass($_POST['email']) == 0) 
	{
        $_SESSION['message'] = "Un email vous a été envoyé pour réinitialiser votre mot de passe";
		header('location:login.php');
	}
}
?>
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="theme.css">
        <link rel="stylesheet" type="text/css" href="login.css">
        <title>Camagru - Login</title>
        <link rel="shortcut icon" href="../img/logo_green.png">        
    </head>
    
    <body background="../img/background2.jpg">
        <header class="container">
            <a href="../index.php"><img id="header_logo" src="../img/logo2.png"></a>
            <h1>Camagru</h1>
            <h2>Réinitialisation</h2>
        </header>
        <div id="nav">
                <ul>
                    <li><a href="montage.php">Montage</a></li>
                    <li><a href="galerie.php">Galerie</a></li>
                    <li><a href="compte.php">Mon Compte</a></li>
                    <li style="float:right"><a href="logout.php">Deconnection</a></li>
                </ul>
        </div>
		<div id="main_wrapper">
            <div id="message">
                <?php if (isset($_SESSION['message'])) {echo $_SESSION['message'];} ?>
            </div>
            <form method="POST" action="forget.php">
                <table class="reinit">
                    <tr>
                        <td class="label">Veuillez indiquer votre adresse mail: </td>
                        <td class="int"><input type="text" name="email" /></td>
                        <td class="int" colspan=2><input type="submit" name="submit" value="Reinitialiser" /></td>
                    </tr>
                </table>
            </form>
        </div>
        <footer>
            Camagru.fr All rights reserved <br />
            Christophe Baldy
        </footer>
    </body>
</html>
