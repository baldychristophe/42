<?php

include ('config.php');
if ($_SESSION['user']['adm'] != 42)
{
  header('location:index.php');
  die();
}

foreach ($_GET as $get) {
  $i++;
}


if ($_POST['test'] === 'user')
{
  $r = "Register";
  if (register($_POST['email'], $_POST['pass'], $_POST['verifpass'], $_POST['nom'], $_POST['prenom'], $r))
  {
    $_SESSION['message'] = "Ajouter avec succes";
    header('location:admin.php');
    die();
  }
  else {
    $message =  "ERROR\n";
  }
}

if ($_POST['test'] === 'prod')
{
  if (new_prod($_POST['name'], $_POST['cate'], $_POST['img'], $_POST['prix']))
  {
    $_SESSION['message'] = "Ajouter avec succes";
    header('location:admin.php');
    die();
  }
  else {
    $message =  "ERROR\n";
  }
}

if ($_POST['test'] === 'cate')
{
  if (new_cate($_POST['name']))
  {
    $_SESSION['message'] = "Ajouter avec succes";
    header('location:admin.php');
    die();
  }
  else {
    $message =  "ERROR\n";
  }
}

if ($i == 0 || $i > 1){
  header('location:admin.php');
  die();
}

?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>New Admin</title>
  </head>
  <body>
    <?php if ($_GET['adduser']){ ?>

      <form action="./adminnew.php?adduser=1" method="post">
          <table class="main"><tbody>
              <tr><td class="int">E-mail: </td><td><input type="text" name="email"><br /></td></tr>
              <tr><td class="int">password: </td><td><input type="password" name="pass"><br /></td></tr>
              <tr><td class="int">verif password: </td><td><input type="password" name="verifpass"><br /></td></tr>
              <tr><td class="int">Nom: </td><td><input type="text" name="nom"><br /></td></tr>
              <tr><td class="int">Prenom: </td><td><input type="text" name="prenom"><br /></td></tr>
              <input type="hidden" name="test" value="user">
              <tr><td class="int" colspan=2><input type="submit" name="submit" value="Add user"></td></tr>
          </tbody></table>

      </form>

    <?php } ?>

    <?php if ($_GET['addprod']){ ?>

      <form action="./adminnew.php?addprod=1" method="post">
          <table class="main"><tbody>
              <tr><td class="int">Nom du produit: </td><td><input type="text" name="name"><br /></td></tr>
              <tr><td class="int">Id Categorie: ex: 1,2,4 </td><td><input type="text" name="cate"><br /></td></tr>
              <tr><td class="int">Url image: </td><td><input type="text" name="img"><br /></td></tr>
              <tr><td class="int">Prix: </td><td><input type="text" name="prix"><br /></td></tr>
              <input type="hidden" name="test" value="prod">
              <tr><td class="int" colspan=2><input type="submit" name="submit" value="Add produits"></td></tr>
          </tbody></table>

      </form>

    <?php } ?>

    <?php if ($_GET['addcate']){ ?>

      <form action="./adminnew.php?addcate=1" method="post">
          <table class="main"><tbody>
              <tr><td class="int">Nom de la categorie : </td><td><input type="text" name="name"><br /></td></tr>
              <input type="hidden" name="test" value="cate">
              <tr><td class="int" colspan=2><input type="submit" name="submit" value="Add categorie"></td></tr>
          </tbody></table>

      </form>

    <?php } ?>
  </body>
</html>
