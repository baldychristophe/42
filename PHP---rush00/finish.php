<?php

include('config.php');
if (!$_SESSION['user'])
{
  header('location:signin.php');
  die();
}

if (finish($_SESSION['panier'], $_SESSION['user']['index']))
{
  $_SESSION['message'] = "Commande Ajouter";
  unset($_SESSION['panier']);
  header('location:index.php');
}

?>
