<?php

include('config.php');

if (isset($_GET['addPanier']))
{
  if (checkadd($_GET['addPanier']))
    $_SESSION['panier'][] = $_GET['addPanier'];
}

if (isset($_GET['id']))
  $res = recherche_cat($_GET['id']);
else
  $res = index();


?>

<!DOCTYPE html>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <link rel="stylesheet" type="text/css" href="index.css">
    <title>Home Page</title>
  </head>
  <body>
    <div id="header">
          <span id="home">
            <a href="index.php"><img src="http://icons.iconarchive.com/icons/custom-icon-design/mono-general-3/128/home-icon.png"></a>
          </span>
          <span>
            <h1>MyLittleBag</h1>
          </span>
     </div>
     <div id="menu">
        <ul class="menu">
    <?php if (isset($_SESSION['message'])){echo $_SESSION['message'];unset($_SESSION['message']);}
            if (isset($_SESSION['user'])){?>
      <?php if (isset($_SESSION['user']['adm']) && $_SESSION['user']['adm'] === 42){ ?>
      <li class="elem"> <a href="./admin.php"> Admin</a></li>
      <?php } ?>
      <li class="elem"><a href="./logout.php">Logout</a></li>
    <?php }else{ ?>
    <li class="elem"><a href="./signin.php">Login</a></li>
    <li class="elem"><a href="./signup.php">Register</a></li>
    <?php } ?>
    <li class="elem"><a href="./panier.php">Panier <?php if (isset($_SESSION['panier'])){?>(<?php echo count_panier($_SESSION['panier']); ?>)<?php } ?></a></li>
 </ul></div>
    <?php if (isset($_SESSION['user'])){?>
    <h1 style="padding:10px;">Bonjours <?php echo $_SESSION['user']['nom'] ?></h1><?php } ?>
<div>
<table class="vue"><tbody>
    <?php
    if ($res)
    {
        $mod = 0;
      foreach ($res as $key) {
        $cat = categories($key['cate']);
        if ($mod % 3 == 0){?> <tr> <?php }
      ?>
        <td class="elem">
            <div class="prix"><?php echo $key['prix']." €"; ?></div>
            <div class="nom"><?php echo $key['name']; ?></div>
        <div class="cat">Categories : <?php foreach ($cat as $c) {
          ?> <a href="./index.php?id=<?php echo $c['id']; ?>"><?php echo $c['name'];?></a> <?php
        }?></div>
        <div class="image"><img src="<?php echo $key['img']; ?>"></div>
        <div class="ajout"><span><a href="./index.php?addPanier=<?php echo $key['index']; ?>">Ajouter au panier</a></span></div>
      </td>
      <?php if ($mod % 3 == 2){?> </tr>
      <?php
        }
        $mod += 1;
      }
    }
      ?>
</tbody></table>
</div>
   <hr>
   <p id="signature"><img width="30px" src="https://asset1.surfcdn.com/eastpak-backpacks-eastpak-padded-pak-r-backpack-chuppachop-red.jpg?w=1200&h=1200&r=4&q=80&o=Zp4z0mmLvpaaC6AFf60GilTtRbMj&V=EVqH">@MyLittleBag.Ltd</p>
  </body>
</html>
