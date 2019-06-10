<?php

include('config.php');

if (isset($_SESSION['user']))
{
  header('location:index.php');
  die();
}

if (login($_POST['email'], $_POST['pass'], $_POST['submit']))
{
  header('location:index.php');
}
if ($_POST['email'])
  $message = "ERROR";

?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <link rel="stylesheet" type="text/css" href="signin.css">
    <title>Login</title>
  </head>
  <body>
      <div id="header">
          <span id="home">
          <a href="index.php"><img src="http://icons.iconarchive.com/icons/custom-icon-design/mono-general-3/128/home-icon.png"></a>
          </span>
          <span>
          <h1>Login</h1>
          </span>
       </div>
    <?php if (isset($message)){?> <h1><?php echo $message; ?></h1> <?php } ?>
        <div id="formulaire">
            <form action="./signin.php" method="post">
                <table class="main"><tbody>
                    <tr><td class="int">Identifiant: </td><td><input type="text" class="ib" name="email" value="<?php if ($_POST['email']){echo $_POST['email'];} ?>"></td></tr>
                    <tr><td class="int">Mot de passe: </td><td><input type="password" class="ib" name="pass"></td></tr>
                    <tr><td class="int" colspan=2><input type="submit" name="submit" value="Login"></td></tr>
                </tbody></table>
            </form>
        </div>
        <hr>
        <p id="signature"><img width="30px" src="https://asset1.surfcdn.com/eastpak-backpacks-eastpak-padded-pak-r-backpack-chuppachop-red.jpg?w=1200&h=1200&r=4&q=80&o=Zp4z0mmLvpaaC6AFf60GilTtRbMj&V=EVqH">@MyLittleBag.Ltd</p>
  </body>
</html>
