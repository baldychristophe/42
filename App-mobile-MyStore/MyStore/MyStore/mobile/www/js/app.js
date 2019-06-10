angular.module('MyStore', ['ionic', 'MyStore.controllers', 'MyStore.datas'])

.run(function($ionicPlatform) {
  $ionicPlatform.ready(function() {
  	
    if (window.cordova && window.cordova.plugins && window.cordova.plugins.Keyboard) {
      cordova.plugins.Keyboard.hideKeyboardAccessoryBar(true);
      cordova.plugins.Keyboard.disableScroll(true);

    }
    if (window.StatusBar) {
      StatusBar.styleDefault();
    }
  });
})

.config(function($stateProvider, $urlRouterProvider) {

  $stateProvider

  // abstract state
    .state('tab', {
    url: '/tab',
    abstract: true,
    templateUrl: 'templates/tabs.html'
  })

  .state('tab.store', {
    url: '/store',
    views: {
      'tab-store': {
        templateUrl: 'templates/tab-store.html',
        controller: 'StoreCtrl'
      }
    }
  })

  .state('tab.cart', {
      url: '/cart',
      views: {
        'tab-cart': {
          templateUrl: 'templates/tab-cart.html',
          controller: 'CartCtrl'
        }
      }
    })
      
    .state('tab.account', {
    url: '/account',
    views: {
      'tab-account': {
        templateUrl: 'templates/tab-account.html',
        controller: 'AccountCtrl'
      }
    }
  	})
    .state('tab.cmd-detail', {
      url: '/account/:cmdId',
      views: {
        'tab-account': {
          templateUrl: 'templates/chat-detail.html',
          controller: 'CmdDetailCtrl'
        }
      }
    });

  $urlRouterProvider.otherwise('/tab/store');

});