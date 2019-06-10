angular.module('starter.controllers', [])

.controller('CartCtrl', function($scope) {})

.controller('StoreCtrl', function($scope, Items) {
  // With the new view caching in Ionic, Controllers are only called
  // when they are recreated or on app start, instead of every page change.
  // To listen for when this page is active (for example, to refresh data),
  // listen for the $ionicView.enter event:
  //
  //$scope.$on('$ionicView.enter', function(e) {
  //});

	  $scope.chats = Items.all();
	  $scope.remove = function(chat) {
	  Items.remove(chat);
  };
})

.controller('ChatDetailCtrl', function($scope, $stateParams, Items) {
  $scope.chat = Chats.get($stateParams.chatId);
})

.controller('AccountCtrl', function($scope) {
  $scope.settings = {
    enableFriends: true
  };
});
