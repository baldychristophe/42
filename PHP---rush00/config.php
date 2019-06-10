<?php
session_start();
$mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
if (!$mysqli)
{
  ?>
  <SCRIPT LANGUAGE="JavaScript">
  document.location.href="./install.php"
  </SCRIPT>

  <?php
  die();
}

function login($email, $pass, $submit)
{
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  if ($email && $pass && $submit === 'Login')
  {
      if (preg_match("#^[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$#i", $email))
      {
        $email = htmlspecialchars($email);
        $stmt = mysqli_stmt_init($mysqli);
        mysqli_stmt_prepare($stmt, "SELECT id, email, password, nom, prenom, adm FROM users WHERE email = ?");
        $pass = hash('whirlpool', $pass);
        mysqli_stmt_bind_param($stmt, 's', $email);
        mysqli_stmt_execute($stmt);
        mysqli_stmt_bind_result($stmt, $index, $email, $mpass, $nom, $prenom, $adm);
        mysqli_stmt_fetch($stmt);
        if ($email != NULL && $mpass != NULL)
        {
          if ($mpass === $pass)
          {
            $_SESSION['user']['email'] = $email;
            $_SESSION['user']['nom'] = $nom;
            $_SESSION['user']['prenom'] = $prenom;
            $_SESSION['user']['adm'] = $adm;
            $_SESSION['user']['index'] = $index;
            return (1);
          }
        }
      }
    }
    return (0);
}

function register($email, $pass, $passverif, $nom, $prenom, $submit)
{
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  if ($email && $pass && $passverif && $nom && $prenom && $submit === 'Register')
  {
    if ($pass === $passverif)
    {
      if (preg_match("#^[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$#i", $_POST['email']))
      {
          $email = htmlspecialchars($email);
          $st = mysqli_stmt_init($mysqli);
          mysqli_stmt_prepare($st, "SELECT email FROM users WHERE email = ?");
          mysqli_stmt_bind_param($st, 's', $email);
          mysqli_stmt_execute($st);
          mysqli_stmt_bind_result($st, $email2);
          mysqli_stmt_fetch($st);
          mysqli_stmt_close($st);
          if ($email2 == NULL)
          {
            $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
            $nom = htmlspecialchars($nom);
            $prenom = htmlspecialchars($prenom);
            $stmt = mysqli_stmt_init($mysqli);
            mysqli_stmt_prepare($stmt, "INSERT INTO users (email, password, nom, prenom) VALUES (?, ?, ?, ?)");
            $pass = hash('whirlpool', $pass);
            mysqli_stmt_bind_param($stmt, 'ssss', $email, $pass, $nom, $prenom);
            if (mysqli_stmt_execute($stmt))
              return (1);
            else
              return (0);
          }
      }

    }
  }
  return (0);
}

function index()
{
        $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
        $stmt = mysqli_stmt_init($mysqli);
        mysqli_stmt_prepare($stmt, "SELECT id, name, categories, img, prix FROM produits");
        mysqli_stmt_execute($stmt);
        mysqli_stmt_bind_result($stmt, $index, $name, $categories, $img, $prix);
        $i = 0;
        while(mysqli_stmt_fetch($stmt))
        {
          $res[$i]['name'] = $name;
          $res[$i]['cate'] = $categories;
          $res[$i]['img'] = $img;
          $res[$i]['prix'] = $prix;
          $res[$i]['index'] = $index;
          $i++;
        }
        return ($res);
}

function categories($cat)
{
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $explo = explode(',', $cat);
  $i = 0;
  foreach ($explo as $key) {
    $stmt = mysqli_stmt_init($mysqli);
    mysqli_stmt_prepare($stmt, "SELECT name, id FROM categories WHERE id=?");
    mysqli_stmt_bind_param($stmt, 's', $key);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_bind_result($stmt, $name, $id);
    mysqli_stmt_fetch($stmt);
    $res[$i]['name'] = $name;
    $res[$i]['id'] = $id;
    $i++;
  }
  return ($res);
}

function recherche_cat($id)
{
  $id = htmlspecialchars($id);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $stmt = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($stmt, "SELECT id, name, categories, img, prix FROM produits");
  mysqli_stmt_execute($stmt);
  mysqli_stmt_bind_result($stmt, $index, $name, $categories, $img, $prix);
  $i = 0;
  while(mysqli_stmt_fetch($stmt))
  {
    $cat = explode(',', $categories);
    foreach ($cat as $key) {
      if ($key === $id)
      {
        $res[$i]['name'] = $name;
        $res[$i]['cate'] = $categories;
        $res[$i]['img'] = $img;
        $res[$i]['prix'] = $prix;
        $res[$i]['index'] = $index;
        $i++;
      }
    }
  }
  return ($res);
}

function checkadd($id)
{
  $id = htmlspecialchars($id);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $stmt = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($stmt, "SELECT id FROM produits WHERE id = ?");
  mysqli_stmt_bind_param($stmt, 's', $id);
  mysqli_stmt_execute($stmt);
  mysqli_stmt_bind_result($stmt, $index);
  mysqli_stmt_fetch($stmt);
  if ($index != NULL)
    return (1);
  return (0);
}

function count_panier($panier)
{
  $i = 0;
  foreach ($panier as $key) {
    $i++;
  }
  return ($i);
}

function reqUser()
{
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $stmt = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($stmt, "SELECT id, email, nom, prenom, adm FROM users");
  mysqli_stmt_execute($stmt);
  mysqli_stmt_bind_result($stmt, $index, $email, $nom, $prenom, $adm);
  $i = 0;
  while(mysqli_stmt_fetch($stmt))
  {
    $res[$i]['email'] = $email;
    $res[$i]['prenom'] = $prenom;
    $res[$i]['nom'] = $nom;
    $res[$i]['adm'] = $adm;
    $res[$i]['index'] = $index;
    $i++;
  }
  return ($res);
}

function reqCat()
{
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $stmt = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($stmt, "SELECT id, name FROM categories");
  mysqli_stmt_execute($stmt);
  mysqli_stmt_bind_result($stmt, $index, $name);
  $i = 0;
  while(mysqli_stmt_fetch($stmt))
  {
    $res[$i]['name'] = $name;
    $res[$i]['index'] = $index;
    $i++;
  }
  return ($res);
}

function reqCmd()
{
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $stmt = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($stmt, "SELECT id, id_user, produits FROM panier");
  mysqli_stmt_execute($stmt);
  mysqli_stmt_bind_result($stmt, $index, $id_user, $prod);
  $i = 0;
  while(mysqli_stmt_fetch($stmt))
  {
    $res[$i]['index'] = $index;
    $res[$i]['id_user'] = $id_user;
    $res[$i]['prod'] = $prod;
    $i++;
  }
  return ($res);
}

function delUser($id)
{
  $id = htmlspecialchars($id);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $st = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($st, "SELECT id FROM users WHERE id = ?");
  mysqli_stmt_bind_param($st, 's', $id);
  mysqli_stmt_execute($st);
  mysqli_stmt_bind_result($st, $index);
  mysqli_stmt_fetch($st);
  if ($index != NULL)
  {
    $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
    $stmt = mysqli_stmt_init($mysqli);
    mysqli_stmt_prepare($stmt, "DELETE FROM users WHERE id = ?");
    mysqli_stmt_bind_param($stmt, 's', $id);
    if (mysqli_stmt_execute($stmt))
    {
      return (1);
    }
    return (0);
  }
  return (0);
}

function delCate($id)
{
  $id = htmlspecialchars($id);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $st = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($st, "SELECT id FROM categories WHERE id = ?");
  mysqli_stmt_bind_param($st, 's', $id);
  mysqli_stmt_execute($st);
  mysqli_stmt_bind_result($st, $index);
  mysqli_stmt_fetch($st);
  if ($index != NULL)
  {
    $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
    $stmt = mysqli_stmt_init($mysqli);
    mysqli_stmt_prepare($stmt, "DELETE FROM categories WHERE id = ?");
    mysqli_stmt_bind_param($stmt, 's', $id);
    if (mysqli_stmt_execute($stmt))
    {
      return (1);
    }
    return (0);
  }
  return (0);
}

function delProd($id)
{
  $id = htmlspecialchars($id);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $st = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($st, "SELECT id FROM produits WHERE id = ?");
  mysqli_stmt_bind_param($st, 's', $id);
  mysqli_stmt_execute($st);
  mysqli_stmt_bind_result($st, $index);
  mysqli_stmt_fetch($st);
  if ($index != NULL)
  {
    $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
    $stmt = mysqli_stmt_init($mysqli);
    mysqli_stmt_prepare($stmt, "DELETE FROM produits WHERE id = ?");
    mysqli_stmt_bind_param($stmt, 's', $id);
    if (mysqli_stmt_execute($stmt))
    {
      return (1);
    }
    return (0);
  }
  return (0);
}

function reqUserId($id)
{
  $id = htmlspecialchars($id);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $stmt = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($stmt, "SELECT id, email, nom, prenom, adm FROM users WHERE id = ?");
  mysqli_stmt_bind_param($stmt, 's', $id);
  mysqli_stmt_execute($stmt);
  mysqli_stmt_bind_result($stmt, $index, $email, $nom, $prenom, $adm);
  mysqli_stmt_fetch($stmt);
  $res['email'] = $email;
  $res['prenom'] = $prenom;
  $res['nom'] = $nom;
  $res['adm'] = $adm;
  $res['index'] = $index;
  return ($res);
}

function reqProdId($id)
{
  $id = htmlspecialchars($id);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $stmt = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($stmt, "SELECT id, name, categories, img, prix FROM produits WHERE id = ?");
  mysqli_stmt_bind_param($stmt, 's', $id);
  mysqli_stmt_execute($stmt);
  mysqli_stmt_bind_result($stmt, $index, $name, $categories, $img, $prix);
  mysqli_stmt_fetch($stmt);
  $res['name'] = $name;
  $res['cate'] = $categories;
  $res['img'] = $img;
  $res['prix'] = $prix;
  $res['index'] = $index;
  return ($res);
}

function reqCateId($id)
{
  $id = htmlspecialchars($id);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $stmt = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($stmt, "SELECT id, name FROM categories WHERE id = ?");
  mysqli_stmt_bind_param($stmt, 's', $id);
  mysqli_stmt_execute($stmt);
  mysqli_stmt_bind_result($stmt, $index, $name);
  mysqli_stmt_fetch($stmt);
  $res['name'] = $name;
  $res['index'] = $index;
  return ($res);
}

function reqPagnier($panier)
{
    foreach($panier as $elem)
    {
        if (isset($test[$elem]))
        {
            $test[$elem]++;
        }else{
            $test[$elem] = 1;
        }
    }
  $id = htmlspecialchars($id);
  $i = 0;
  $j = 0;
  $hihi[] = 0;
  foreach ($panier as $key) {
    $k = 1;
    foreach ($hihi as $val) {
      if ($val === $key)
      {
        $k = 0;
      }
    }
    if ($k == 1)
    {
      $hihi[] = $key;
      $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
      $stmt = mysqli_stmt_init($mysqli);
      mysqli_stmt_prepare($stmt, "SELECT id, name, categories, img, prix FROM produits WHERE id = ?");
      mysqli_stmt_bind_param($stmt, 's', $key);
      mysqli_stmt_execute($stmt);
      mysqli_stmt_bind_result($stmt, $index, $name, $categories, $img, $prix);
      mysqli_stmt_fetch($stmt);
      $res[$i]['name'] = $name;
      $res[$i]['cate'] = $categories;
      $res[$i]['img'] = $img;
      $res[$i]['prix'] = $prix;
      $res[$i]['index'] = $index;
      $res[$i]['qte'] = $test[$key];
      $i++;
    }
  }
  return ($res);
}

function editUser($email, $pass, $passverif, $nom, $prenom, $submit, $adm, $id)
{
  $id = htmlspecialchars($id);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  if ($email && $nom && $prenom && $id && $submit === 'Modifier')
  {

      if (preg_match("#^[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$#i", $_POST['email']))
      {
          $email = htmlspecialchars($email);
          $st = mysqli_stmt_init($mysqli);
          mysqli_stmt_prepare($st, "SELECT id FROM users WHERE id = ?");
          mysqli_stmt_bind_param($st, 's', $id);
          mysqli_stmt_execute($st);
          mysqli_stmt_bind_result($st, $id2);
          mysqli_stmt_fetch($st);
          mysqli_stmt_close($st);
          if ($id2 != NULL)
          {
            $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
            $nom = htmlspecialchars($nom);
            $prenom = htmlspecialchars($prenom);
            $adm = htmlspecialchars($adm);
            $stmt = mysqli_stmt_init($mysqli);
            if ($pass && $pass === $passverif){
              $pass = hash('whirlpool', $pass);
              mysqli_stmt_prepare($stmt, "UPDATE users SET  email = ?, password = ?, nom = ?, prenom = ?, adm = ? WHERE  id = ?");
              mysqli_stmt_bind_param($stmt, 'ssssss', $email, $pass, $nom, $prenom, $adm, $id);
            }
            else {
              mysqli_stmt_prepare($stmt, "UPDATE users SET  email = ?, nom = ?, prenom = ?, adm = ? WHERE  id = ?");
              mysqli_stmt_bind_param($stmt, 'sssss', $email, $nom, $prenom, $adm, $id);
            }
            if (mysqli_stmt_execute($stmt))
              return (1);
            else
              return (0);
          }
      }
  }
  return (0);
}

function editProd($name, $cate, $img, $prix, $submit, $id)
{
  $id = htmlspecialchars($id);
  $name = htmlspecialchars($name);
  $cate = htmlspecialchars($cate);
  $img = htmlspecialchars($img);
  $prix = htmlspecialchars($prix);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  if ($name && $cate && $img && $prix && $submit === 'Modifier')
  {
          $st = mysqli_stmt_init($mysqli);
          mysqli_stmt_prepare($st, "SELECT id FROM produits WHERE id = ?");
          mysqli_stmt_bind_param($st, 's', $id);
          mysqli_stmt_execute($st);
          mysqli_stmt_bind_result($st, $id2);
          mysqli_stmt_fetch($st);
          mysqli_stmt_close($st);
          if ($id2 != NULL)
          {
            $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
            $stmt = mysqli_stmt_init($mysqli);
            mysqli_stmt_prepare($stmt, "UPDATE produits SET  name = ?, categories = ?, img = ?, prix = ? WHERE  id = ?");
            mysqli_stmt_bind_param($stmt, 'sssss', $name, $cate, $img, $prix, $id);
            if (mysqli_stmt_execute($stmt))
              return (1);
            else
              return (0);
          }
  }
  return (0);
}

function editCate($name, $submit, $id)
{
  $id = htmlspecialchars($id);
  $name = htmlspecialchars($name);
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  if ($name && $submit === 'Modifier')
  {
          $st = mysqli_stmt_init($mysqli);
          mysqli_stmt_prepare($st, "SELECT id FROM categories WHERE id = ?");
          mysqli_stmt_bind_param($st, 's', $id);
          mysqli_stmt_execute($st);
          mysqli_stmt_bind_result($st, $id2);
          mysqli_stmt_fetch($st);
          mysqli_stmt_close($st);
          if ($id2 != NULL)
          {
            $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
            $stmt = mysqli_stmt_init($mysqli);
            mysqli_stmt_prepare($stmt, "UPDATE categories SET  name = ? WHERE  id = ?");
            mysqli_stmt_bind_param($stmt, 'ss', $name, $id);
            if (mysqli_stmt_execute($stmt))
              return (1);
            else
              return (0);
          }
  }
  return (0);
}

function new_prod($name, $cate, $img, $prix)
{
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  if ($name && $cate && $img && $prix)
  {
          $name = htmlspecialchars($name);
          $cate = htmlspecialchars($cate);
          $img = htmlspecialchars($img);
          $prix = htmlspecialchars($prix);
            $stmt = mysqli_stmt_init($mysqli);
            mysqli_stmt_prepare($stmt, "INSERT INTO produits (name, categories, img, prix) VALUES (?, ?, ?, ?)");
            mysqli_stmt_bind_param($stmt, 'ssss', $name, $cate, $img, $prix);
            if (mysqli_stmt_execute($stmt))
              return (1);
  }
  return (0);
}

function new_cate($name)
{
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  if ($name)
  {
          $name = htmlspecialchars($name);
            $stmt = mysqli_stmt_init($mysqli);
            mysqli_stmt_prepare($stmt, "INSERT INTO categories (name) VALUES (?)");
            mysqli_stmt_bind_param($stmt, 's', $name);
            if (mysqli_stmt_execute($stmt))
              return (1);
  }
  return (0);
}

function panierSuppr($id, $panier)
{
  $i = 0;
  foreach ($panier as $key) {
    if ($id != $i){
      $res[] = $key;
    }
    $i++;
  }
  return ($res);
}

function count_total($panier)
{
  $i = 0;
  foreach ($panier as $key) {
    $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
    $stmt = mysqli_stmt_init($mysqli);
    mysqli_stmt_prepare($stmt, "SELECT id, name, categories, img, prix FROM produits WHERE id = ?");
    mysqli_stmt_bind_param($stmt, 's', $key);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_bind_result($stmt, $index, $name, $categories, $img, $prix);
    mysqli_stmt_fetch($stmt);
    $res[$i]['name'] = $name;
    $res[$i]['cate'] = $categories;
    $res[$i]['img'] = $img;
    $res[$i]['prix'] = $prix;
    $res[$i]['index'] = $index;
    $res[$i]['qte'] = $test[$key];
    $i++;
  }
  $i = 0;
  $prix = 0;
  while ($res[$i])
  {
    $prix = $prix + $res[$i]['prix'];
    $i++;
  }
  return ($prix);
}

function finish($panier, $index_user)
{
  $i = 0;
  foreach ($panier as $key) {
    if ($i == 0){
      $text = $key;
    }
    else {
      $text = $text.",".$key;
    }
    $i++;
  }
  $mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop", "minishoppassword", "shop");
  $stmt = mysqli_stmt_init($mysqli);
  mysqli_stmt_prepare($stmt, "INSERT INTO panier (id_user, produits) VALUES (?, ?)");
  mysqli_stmt_bind_param($stmt, 'ss', $index_user, $text);
  if(mysqli_stmt_execute($stmt)){
    return (1);
  }
  echo $text;
  return (0);
}

?>
