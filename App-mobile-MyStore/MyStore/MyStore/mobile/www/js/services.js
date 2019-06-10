angular.module('MyStore.datas', [])

.factory('Commands', function(){
	
	var commands = [];
	
	return {
    all: function() {
      return commands;
    },
	 get: function(cmdId) {
      for (var i = 0; i < commands.length; i++) {
        if (commands[i].id === parseInt(cmdId)) {
          return commands[i];
        }
      }
      return null;
    }
  };
})

.factory('Items', function() {
 
  var items = [{
    id: 0,
    title: 'Eastpak rouge',
    price: 15.00,
    quant: 0,
    img: 'img/eastpak_rouge.jpeg',
  }, {
    id: 1,
    title: 'Eastpak bleu',
    price: '14.99',
    quant: 0,
    img: 'img/eastpak_bleu.jpeg',
  }, {
    id: 2,
    title: 'Eastpak noir',
    price: '19.99',
    quant: 0,
    img: 'img/eastpak_noir.jpeg',
  }, {
    id: 3,
    title: 'Eastpak rose',
    price: '20.00',
    quant: 0,
    img: 'img/eastpak_rose.jpeg',
  }, {
    id: 4,
    title: 'Eastpak ciel',
    price: '19.99',
    quant: 0,
    img: 'img/eastpak_ciel.jpeg',
    cart: true
  }, {
    id: 5,
    title: 'Eastpak marron',
    price: '25.00',
    quant: 0,
    img: 'img/eastpak_marron.jpeg',
  }, {
    id: 6,
    title: 'Eastpak gris',
    price: '22.99',
    quant: 0,
    img: 'img/eastpak_gris.jpeg',
  }, {
    id: 7,
    title: 'Eastpak bleu autre',
    price: '22.99',
    quant: 0,
    img: 'img/eastpak_bleu.jpeg',
  }, {
    id: 8,
    title: 'Eastpak coloré',
    price: '17.99',
    quant: 0,
    img: 'img/eastpak_colore.jpeg',
  }];
	
  return {
    all: function() {
      return items;
    },
    get: function(itemId) {
      for (var i = 0; i < items.length; i++) {
        if (items[i].id === parseInt(itemId)) {
          return items[i];
        }
      }
      return null;
    }
  };
});