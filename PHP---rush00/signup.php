<?php

include('config.php');

if (isset($_SESSION['user']))
{
  header('location:index.php');
  die();
}

if ($_POST['submit'])
{
  if (register($_POST['email'], $_POST['pass'], $_POST['verifpass'], $_POST['nom'], $_POST['prenom'], $_POST['submit']))
  {
    $_SESSION['message'] = "Votre compte a bien ete creer";
    header('location:index.php');
  }
  else {
    $message =  "ERROR\n";
  }
}

?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Register</title>
    <link rel="stylesheet" type="text/css" href="signup.css">
  </head>
  <body>
      <div id="header">
          <span id="home">
          <a href="index.php"><img src="http://icons.iconarchive.com/icons/custom-icon-design/mono-general-3/128/home-icon.png"></a>
          </span>
          <span>
          <h1>Inscription</h1>
          </span>
       </div>
    <?php if (isset($message)){?> <h1><?php echo $message; ?></h1> <?php } ?>
    <div id="formulaire">
        <form action="./signup.php" method="post">
            <table class="main"><tbody>
                <tr><td class="int">E-mail: </td><td><input type="text" name="email" value="<?php if ($_POST['email']){echo $_POST['email'];} ?>"><br /></td></tr>
                <tr><td class="int">password: </td><td><input type="password" name="pass"><br /></td></tr>
                <tr><td class="int">verif password: </td><td><input type="password" name="verifpass"><br /></td></tr>
                <tr><td class="int">Nom: </td><td><input type="text" name="nom"><br /></td></tr>
                <tr><td class="int">Prenom: </td><td><input type="text" name="prenom"><br /></td></tr>
                <tr><td class="int" colspan=2><input type="submit" name="submit" value="Register"></td></tr>
            </tbody></table>
            
        </form>
    </div>
   <hr>
   <p id="signature"><img width="30px" src="https://asset1.surfcdn.com/eastpak-backpacks-eastpak-padded-pak-r-backpack-chuppachop-red.jpg?w=1200&h=1200&r=4&q=80&o=Zp4z0mmLvpaaC6AFf60GilTtRbMj&V=EVqH">@MyLittleBag.Ltd</p>
  </body>
</html>
