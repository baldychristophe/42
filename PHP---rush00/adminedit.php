<?php

  include('config.php');

  if ($_SESSION['user']['adm'] != 42)
  {
    header('location:index.php');
    die();
  }
  $i = 0;
  foreach ($_GET as $get) {
    $i++;
  }
  if ($_POST['test'] === 'user')
  {
    if (editUser($_POST['email'], $_POST['pass'], $_POST['passverif'], $_POST['nom'], $_POST['prenom'], $_POST['submit'], $_POST['adm'], $_GET['editUser'])){
      $_SESSION['message'] = "L'utilisateur a ete modifier";
      header('location:admin.php');
    }
  }
  if ($_POST['test'] === 'prod')
  {
    if (editProd($_POST['name'], $_POST['cate'], $_POST['img'], $_POST['prix'], $_POST['submit'], $_GET['editProd'])){
      $_SESSION['message'] = "Le produit a ete modifier";
      header('location:admin.php');
    }
  }
  if ($_POST['test'] === 'cate')
  {
    if (editCate($_POST['name'], $_POST['submit'], $_GET['editCat'])){
      $_SESSION['message'] = "La categorie a ete modifier";
      header('location:admin.php');
    }
  }
  if ($i == 0 || $i > 1){
    header('location:admin.php');
    die();
  }
    if ($_GET['delUser'])
    {
      if (delUser($_GET['delUser']))
        $_SESSION['message'] = "L'utilisateur a ete supprimé";
      else {
        $_SESSION['message'] = "Error : L'utilisateur inexistent";
      }
      header('location:admin.php');
      die();
    }
    if ($_GET['delProd'])
    {
      if (delProd($_GET['delProd']))
        $_SESSION['message'] = "Le produit a ete supprimé";
      else {
        $_SESSION['message'] = "Error : produit inexistent";
      }
      header('location:admin.php');
      die();
    }
    if ($_GET['delCat'])
    {
      if (delCate($_GET['delCat']))
        $_SESSION['message'] = "La categorie a ete supprimé";
      else {
        $_SESSION['message'] = "Error : categorie inexistent";
      }
      header('location:admin.php');
      die();
    }
    if ($_GET['editUser'])
    {
      $user = reqUserId($_GET['editUser']);
      if ($user['email'] == NULL){
        header('location:admin.php');
        die();
      }
    }
    if ($_GET['editProd'])
    {
      $prod = reqProdId($_GET['editProd']);
      if ($prod['index'] == NULL){
        header('location:admin.php');
        die();
      }
    }
    if ($_GET['editCat'])
    {
      $cate = reqCateId($_GET['editCat']);
      if ($cate['index'] == NULL){
        header('location:admin.php');
        die();
      }
    }
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Edit Admin</title>
  </head>
  <body>
    <h1>Edit</h1>




    <?php if ($_GET['editUser']) {
      ?>
      <form action="./adminedit.php?editUser=<?php echo $user['index']; ?>" method="post">
        E-mail*:<br />
        <input type="text" name="email" value="<?php echo $user['email']; ?>"><br />
        Nom*:<br />
        <input type="text" name="nom" value="<?php echo $user['nom']; ?>"><br />
        Prenom*:<br />
        <input type="text" name="prenom" value="<?php echo $user['prenom']; ?>"><br /><br />
        mot de passe vide ou différent entre password et verif password = pas de changement du password<br />
        Password:<br />
        <input type="password" name="pass"><br />
        Verif password:<br />
        <input type="password" name="passverif"><br /><br />
        Admin:
        <input type="checkbox" name="adm" value="42"  <?php if ($user['adm']){ echo "checked";} ?>><br>
        <br /><br />
        <input type="hidden" name="test" value="user">
        <input type="submit" name="submit" value="Modifier">
      </form>

      <?php } ?>

      <?php if ($_GET['editProd']) {
        ?>
        <form action="./adminedit.php?editProd=<?php echo $prod['index']; ?>" method="post">
          Nom du produits:<br />
          <input type="text" name="name" value="<?php echo $prod['name']; ?>"><br />
          Id categories: ex: 1,2,5<br />
          <input type="text" name="cate" value="<?php echo $prod['cate']; ?>"><br />
          Url Img:<br />
          <input type="text" name="img" value="<?php echo $prod['img']; ?>"><br />
          Prix:<br />
          <input type="text" name="prix" value="<?php echo $prod['prix']; ?>"> €
          <br /><br />
          <input type="hidden" name="test" value="prod">
          <input type="submit" name="submit" value="Modifier">
        </form>

        <?php } ?>

        <?php if ($_GET['editCat']) {
          ?>
          <form action="./adminedit.php?editCat=<?php echo $cate['index']; ?>" method="post">
            Nom de la categorie:<br />
            <input type="text" name="name" value="<?php echo $cate['name']; ?>"><br />
            <br /><br />
            <input type="hidden" name="test" value="cate">
            <input type="submit" name="submit" value="Modifier">
          </form>

          <?php } ?>





  </body>
</html>
