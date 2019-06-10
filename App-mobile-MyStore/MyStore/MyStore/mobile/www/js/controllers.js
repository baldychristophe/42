angular.module('MyStore.controllers', [])

.controller('CartCtrl', function($scope, Items, Commands) {
	
	$scope.carts = Items.all();
	$scope.remove = function(item) {
		$tmp = Items.get(item.id);
		$tmp.quant -= 1;
	};
	
	$scope.total = function() {
		var tmp = Items.all();
		var tot = 0;
		for (item of tmp) {
			tot += item.quant * item.price;
		}
		return tot;
	};
	
	$scope.clear = function() {
		var tmp = Items.all();
		for (item of tmp) {
			item.quant = 0;
		}
	};
	
	$scope.nb = function() {
		var tmp = Items.all();
		var count = 0;
		for (item of tmp) {
			count += item.quant;
		}
		return count;
	};

	$scope.get_content = function() {
		var buf = [];
		var curr = Items.all();
		for (item of curr) {
			if (item.quant > 0) {
				buf.push(item);
			}
		}
		var newbuf = [];
		angular.copy(buf, newbuf);
		return newbuf;
	}
	
	$scope.save = function() {
		var tmp = Commands.all();
		var content = [];
		var elem = {
			id: tmp.length + 1,
			price: $scope.total(),
			nb: $scope.nb(),
			content: $scope.get_content(),
		};
		tmp.push(elem);
		$scope.clear();
	};
})

.controller('StoreCtrl', function($scope, Items) {

		$scope.items = Items.all();
  		
  		$scope.add = function (item) {
  			$tmp = Items.get(item.id);
  			$tmp.quant += 1;
  		};
})

.controller('CmdDetailCtrl', function($scope, $stateParams, Items, Commands) {
  $scope.cmd = Commands.get($stateParams.cmdId);
  
  $scope.test = function() {
  		return $scope.cmd.content.id
  };
})

.controller('AccountCtrl', function($scope, Items, Commands) {
  
  	$scope.nb_cmd = function() {
		var tmp = Commands.all();
		return (tmp.length);
	};
	
	$scope.cmd = Commands.all();
});
