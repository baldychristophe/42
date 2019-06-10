<?php

  include('config.php');
  if ($_SESSION['user']['adm'] != 42)
  {
    header('location:index.php');
    die();
  }

  $users = reqUser();
  $produits = index();
  $categories = reqCat();
  $panier = reqCmd();
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Admin</title>
    <link rel="stylesheet" type="text/css" href="admin.css">
  </head>
  <body>
      <div id="header">
          <span id="home">
          <a href="index.php"><img src="http://icons.iconarchive.com/icons/custom-icon-design/mono-general-3/128/home-icon.png"></a>
          </span>
          <span>
          <h1>Admin</h1>
          </span>
       </div>
    <?php if (isset($_SESSION['message'])){ ?> <h2></h2> <?php echo $_SESSION['message']; ?></h2><?php unset($_SESSION['message']); } ?>
    <h3>Users</h3>
    <div class="ajout"><span><a href="./adminnew.php?adduser=1">New user</a></span></div>
    <table class="main"><tbody>
        <tr class="label">
            <td class="cat">id</td>
            <td class="cat">email</td>
            <td class="cat">prenom</td>
            <td class="cat">nom</td>
            <td class="cat">is admin</td>
            <td class="action">Action</td>
       </tr>
       <?php foreach ($users as $user) { ?>

         <tr class="prod">
              <td class="cat"><?php echo $user['index']; ?></td>
              <td class="cat"><?php echo $user['email']; ?></td>
              <td class="cat"><?php echo $user['prenom']; ?></td>
              <td class="cat"><?php echo $user['nom']; ?></td>
              <td class="cat"><?php if ($user['adm'] === 42){ echo "oui";}else{echo "non";} ?></td>
              <td class="action"><a href="./adminedit.php?editUser=<?php echo $user['index'] ?>">Edit</a> <a href="./adminedit.php?delUser=<?php echo $user['index'] ?>">Del</a></td>
         </tr>
       <?php } ?>

   </tbody></table>
   <hr>
   <h3>Produits</h3>
   <div class="ajout"><span><a class="new_prod" href="./adminnew.php?addprod=1">New produits</a></span></div>
   <table class="main"><tbody>
       <tr class="label">
           <td class="cat">id</td>
           <td class="cat">Nom du produit</td>
           <td class="cat">categorie</td>
           <td class="image">Image</td>
           <td class="prix">Prix</td>
           <td class="action">Action</td>
      </tr>
      <?php foreach ($produits as $produit) {

        $cat = categories($produit['cate']);
        ?>

        <tr class="prod">
             <td class="cat"><?php echo $produit['index']; ?></td>
             <td class="cat"><?php echo $produit['name']; ?></td>
             <td class="cat"><?php foreach ($cat as $c) { echo $c['name']." "; } ?></td>
             <td class="image"><?php echo $produit['img']; ?></td>
             <td class="prix"><?php echo $produit['prix']; ?> €</td>
             <td class="action"><a href="./adminedit.php?editProd=<?php echo $produit['index'] ?>">Edit</a> <a href="./adminedit.php?delProd=<?php echo $produit['index'] ?>">Del</a></td>
        </tr>
      <?php } ?>
  </tbody></table>
  <hr>

  <h3>Categories</h3>
  <div class="ajout"><span><a href="./adminnew.php?addcate=1">New categorie</a></span></div>
  <table class="main"><tbody>
      <tr class="label">
          <td class="cat">id</td>
          <td class="cat">Nom de la categorie</td>
          <td class="action">Action</td>
     </tr>
     <?php foreach ($categories as $categorie) { ?>

       <tr class="prod">
            <td class="cat"><?php echo $categorie['index']; ?></td>
            <td class="cat"><?php echo $categorie['name']; ?></td>
            <td class="action"><a href="./adminedit.php?editCat=<?php echo $categorie['index'] ?>">Edit</a> <a href="./adminedit.php?delCat=<?php echo $categorie['index'] ?>">Del</a></td>
       </tr>
     <?php } ?>

 </tbody></table>
 <hr>

 <h3>Commande</h3>
 <div class="ajout"><span><a href="./adminnew.php?addcate=1">New categorie</a></span></div>
 <table class="main"><tbody>
     <tr class="label">
         <td class="cat">ID</td>
         <td class="cat">ID User</td>
         <td class="cat">Commande en ID</td>
    </tr>
    <?php foreach ($panier as $pan) { ?>

      <tr class="prod">
           <td class="cat"><?php echo $pan['index']; ?></td>
           <td class="cat"><?php echo $pan['id_user']; ?></td>
           <td class="cat"><?php echo $pan['prod']; ?></td>
      </tr>
    <?php } ?>

</tbody></table>
<hr>
   <p id="signature"><img width="30px" src="https://asset1.surfcdn.com/eastpak-backpacks-eastpak-padded-pak-r-backpack-chuppachop-red.jpg?w=1200&h=1200&r=4&q=80&o=Zp4z0mmLvpaaC6AFf60GilTtRbMj&V=EVqH">@MyLittleBag.Ltd</p>
  </body>
</html>
