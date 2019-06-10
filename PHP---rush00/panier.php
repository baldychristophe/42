<?php

  include('config.php');

  if (isset($_SESSION['panier'])){
    if ($_POST['submit'] === 'Supprimer'){
      $_SESSION['panier'] = panierSuppr($_POST['suppr'], $_SESSION['panier']);
    }
  }

  if (isset($_SESSION['panier'])){
    $prod = reqPagnier($_SESSION['panier']);
    $_SESSION['panier'] = array_values($_SESSION['panier']);
  }

?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Panier</title>
    <link rel="stylesheet" type="text/css" href="panier.css">
  </head>
  <body>
      <div id="header">
          <span id="home">
            <a href="index.php"><img src="http://icons.iconarchive.com/icons/custom-icon-design/mono-general-3/128/home-icon.png"></a>
          </span>
          <span>
            <h1>Votre Panier</h1>
          </span>
     </div>
     <br />
     <?php if (isset($prod)){ ?>
     <table class="main"><tbody>
         <tr class="label">
<<<<<<< HEAD
             <td class="photo">photo</td>
             <td class="name">nom</td>
             <td class="cat">categorie</td>
              <td class="cat">quantité</td>
             <td class="prix">prix unité</td>
=======
             <td class="photo">Photo</td>
             <td class="name">Nom</td>
             <td class="cat">Categorie</td>
              <td class="cat">Quantité</td>
             <td class="prix">Prix unité</td>
>>>>>>> 209999069b78c8b023f28f5f92dcad8d8ccf80a7
             <td class="action"></td>
        </tr>
        <?php
        $i = 0;
        $total = 0;
        foreach ($prod as $key) {
          $cat = categories($key['cate']);
          $p = reqProdId($key['index']);
          $total = $total + $key['prix'];

          ?>

          <tr class="prod">
               <td class="photo"><img width="30px" src="<?php echo $p['img']; ?>"></td>
               <td class="name"><?php echo $p['name']; ?></td>
               <td class="cat"><?php foreach ($cat as $c) {
                 ?> <?php echo $c['name'];?><?php
               }?></td>
                <td class="cat"><?php echo $key['qte']; ?></td>
               <td class="prix"><?php echo $p['prix']; ?> Euros</td>
               <td class="action"> <form class="" action="./panier.php" method="post">
                 <input type="hidden" name="suppr" value="<?php echo $i; ?>">
                <INPUT class="supp" type="submit" name="submit" value="Supprimer">
               </form></td>
          </tr>

          <?php
          $i++;
        } ?>
<<<<<<< HEAD
        <tr><td id="total" colspan=5> TOTAL <?php echo $total." €"; ?>
=======
        <tr><td id="total" colspan=5> TOTAL <?php echo count_total($_SESSION['panier'])." €"; ?>
>>>>>>> 209999069b78c8b023f28f5f92dcad8d8ccf80a7
   </td></tr>
    </tbody></table>
    <?php


?>
<a href="./finish.php">Valider</a>
<?php


   }else{ ?>

       <h1>Aucun article</h1>



       <?php } ?>
    <hr>
    <p id="signature"><img width="30px" src="https://asset1.surfcdn.com/eastpak-backpacks-eastpak-padded-pak-r-backpack-chuppachop-red.jpg?w=1200&h=1200&r=4&q=80&o=Zp4z0mmLvpaaC6AFf60GilTtRbMj&V=EVqH">@MyLittleBag.Ltd</p>
  </body>
</html>
