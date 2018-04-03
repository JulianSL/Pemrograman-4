#include <iostream>
#include <list>
#include "Order.h"

using namespace std;

class Stock {
	private:
		string name = "ABC";
		int quantity = 10;
	
	public:
		void buy(){
			cout<<endl<<"Stock [ Name: "<<name<<", Quantity: " << quantity <<" ] bought";
		}
		void sell(){
			cout<<endl<<"Stock [ Name: "<<name<<", Quantity: " << quantity <<" ] sold";
		}
};

class BuyStock: public Order {
	private:
		Stock abcStock;
	public:
		BuyStock(Stock abcStock):Order(){
			abcStock = abcStock;
		}
		
		void execute(){
			abcStock.buy();
		}
};

class SellStock: public Order {
	private:
		Stock abcStock;
	
	public:
		SellStock(Stock abcStock):Order(){
			abcStock = abcStock;
		}
		
		void execute(){
			abcStock.sell();
		}
};

class Broker {
	private:
		list<Order> orderList ; 
	
	public:
		void takeOrder(Order order){
			orderList.push_front(order);
		}
		
		void placeOrders(){
			for (Order order : orderList) {
				order.execute();
			}
			orderList.remove();
		}
};

class CommandPatternDemo {
   int main() {
      Stock abcStock = new Stock();

      BuyStock buyStockOrder = new BuyStock(abcStock);
      SellStock sellStockOrder = new SellStock(abcStock);

      Broker broker = new Broker();
      broker.takeOrder(buyStockOrder);
      broker.takeOrder(sellStockOrder);

      broker.placeOrders();
      return 0;
   }
};
