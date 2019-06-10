<?php

  include('config.php');
  unset($_SESSION['user']);
  $_SESSION['message'] = "Vous avez été deconecté";
  header('location:index.php');
 ?>
