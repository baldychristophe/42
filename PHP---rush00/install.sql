SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";
CREATE DATABASE `shop` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `shop`;
CREATE TABLE IF NOT EXISTS `categories` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=15 ;
INSERT INTO `categories` (`id`, `name`) VALUES
(1, 'Sac a dos'),
(3, 'noir'),
(4, 'rouge'),
(5, 'gris'),
(7, 'Sac a Main'),
(8, 'Bleu'),
(9, 'orange'),
(10, 'marron'),
(11, 'pochette'),
(12, 'rose'),
(13, 'sac de voyage');
CREATE TABLE IF NOT EXISTS `panier` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_user` int(11) NOT NULL,
  `produits` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;
INSERT INTO `panier` (`id`, `id_user`, `produits`) VALUES
(3, 2, '5,4,1'),
(4, 2, '5,4,4,25');

CREATE TABLE IF NOT EXISTS `produits` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `categories` varchar(255) NOT NULL,
  `img` varchar(255) NOT NULL,
  `prix` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=30 ;

INSERT INTO `produits` (`id`, `name`, `categories`, `img`, `prix`) VALUES
(1, 'Eastpak rouge', '1,4', 'https://asset1.surfcdn.com/eastpak-backpacks-eastpak-padded-pak-r-backpack-chuppachop-red.jpg?w=1200&amp;h=1200&amp;r=4&amp;q=80&amp;o=Zp4z0mmLvpaaC6AFf60GilTtRbMj&amp;V=EVqH', 30),
(4, 'Eastpak noir', '1,3', 'https://photos6.spartoo.com/photos/231/231515/Eastpak-PADDED-PAK-R-24L-231515_350_A.jpg', 60),
(5, 'Eastpak gris', '1,5', 'https://photos6.spartoo.com/photos/231/231536/Eastpak-SMALL-ORBIT-10L-231536_350_A.jpg', 4),
(6, 'test2', '1', 'http://eastpak.scene7.com/is/image/Eastpak/EK06A_26K?id=GAamZ1&amp;fmt=jpg&amp;fit=constrain,1&amp;wid=500&amp;hei=500', 50),
(10, 'Eastpak turquoise', '1,8', 'https://kickz.akamaized.net/fr/media/images/p/600/eastpak-PADDED_PAK_R-light_blue-1.jpg', 40),
(11, 'Eastpak orange', '1,9', 'http://photos6.spartoo.com/photos/179/1797428/Eastpak-PADDED-PAK-R-24L-1797428_1200_A.jpg', 29),
(12, 'Eastpak fleuri', '1,4,8,9', 'https://thetreasurehunteruk.files.wordpress.com/2012/02/eastpak-florid-all-design-backpack-c2a339-99-surfdome-com.jpg', 29),
(14, 'Sac sceau cuir', '7,3', 'http://media.laredoute.com/products2/250by250/c/c/1/500779473_0_PR_1_1200.jpg', 99),
(15, 'Sac a main noir', '7,3', 'http://media.laredoute.com/products2/250by250/3/f/8/350021011_0_PR_1_12146978_350021011-2d12033c-c5e5-49d7-bb27-7bb4987abaea_1200.jpg', 99),
(17, 'Sac Ã  main en cuir vachette faÃ§on croco', '7,4', 'http://media.laredoute.com/products2/250by250/3/2/7/500779108_0_PR_1_1200.jpg', 99),
(18, 'Sac a main - LAURA CLEMENT', '7,9', 'http://media.laredoute.com/products2/250by250/0/5/7/350020982_0_PR_1_12146983_350020982-58dfc9e0-2add-4428-a81f-ae21069d3e51_1200.jpg', 49),
(19, 'Sac florida', '7,3', 'http://media.laredoute.com/products2/250by250/d/d/b/500743259_0_PR_1_600.jpg', 79),
(20, 'Sac a main et croute de cuir', '7,8', 'http://media.laredoute.com/products2/250by250/a/5/c/500781350_0_PR_1_1200.jpg', 99),
(21, 'Sac a main vernis', '7,3', 'http://media.laredoute.com/products2/250by250/0/4/9/350020996_0_PR_1_12147007_350020996-fe349363-5e99-428e-a4e2-67a6b9ab970b_1200.jpg', 49),
(22, 'Sac a main', '7,10', 'http://media.laredoute.com/products2/250by250/0/c/2/350021112_0_PR_1_12147037_350021112-08843714-5b28-4cf9-b7f7-8ff4d2a6202f_1200.jpg', 49),
(23, 'pochette zippÃ©e', '7,11', 'http://media.laredoute.com/products2/250by250/b/b/4/500652085_1000_CO_1_1200.jpg', 6),
(24, 'Sac a main en cuir', '7,10', 'http://media.laredoute.com/products2/250by250/6/2/e/500688121_1009_CO_1_1200.jpg', 179),
(25, 'Sac a mian sissi', '7,10', 'http://media.laredoute.com/products2/250by250/c/7/d/500751775_0_PR_1_1200.jpg', 130),
(27, 'Sac marche nordic', '13,8,5', 'http://i2.cdscdn.com/pdt2/8/8/2/1/300x300/auc6879199360882/rw/sac-a-dos-50l-etanche-de-randonnee-campagne-voyage.jpg', 69),
(28, 'Sac randonnÃ©e', '3,13', 'http://i2.cdscdn.com/pdt2/2/3/6/1/300x300/mou5052776027236/rw/tor-sac-a-dos-randonnee-marche-voyage-multi-poches.jpg', 49),
(29, 'Sac Deuter Futura', '3,5,13', 'http://i2.cdscdn.com/pdt2/8/0/8/1/300x300/deu4046051020808/rw/deuter-futura-pro-34-sl-noir-gris.jpg', 105);

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `adm` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=13 ;

INSERT INTO `users` (`id`, `email`, `password`, `nom`, `prenom`, `adm`) VALUES
(2, 'hugoo.frely@gmail.com', 'c43b2c75f76a7007d5efbb073acfd3b12d87c6e084f9bd28d46b2b5dc4ce9104a7b5fb288eac5ca49084cd75c272822ef7de5601e8e831f6eb64f9c9044a035c', 'frely', 'hugo', 42),
(9, 'c.v@lol.fr', '52897b00e528ca357cea0f55b24d657252040d780005764d886023022fda9381db8dcb12361c6b45f9479680ca2a5b46ed0c6b0d565aaccc8ccfa0792dae58b8', 'test', 'test', 42),
(11, 'test@test.fr', 'c43b2c75f76a7007d5efbb073acfd3b12d87c6e084f9bd28d46b2b5dc4ce9104a7b5fb288eac5ca49084cd75c272822ef7de5601e8e831f6eb64f9c9044a035c', 'hugo', 'hugo', NULL);
