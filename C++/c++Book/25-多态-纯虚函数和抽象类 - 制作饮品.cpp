#include "00-main.h"

// 饮品抽象类
class AbstractDrinking {
public:
	// 煮水
	virtual void Boil() { cout << "煮山泉水" << endl; }
	// 冲泡
	virtual void Brew() = 0;
	// 倒入杯中
	virtual void PourInCup() { cout << "倒入杯中" << endl; }
	// 加入辅料
	virtual void PutSomeThing() = 0;
	
	// 制作饮品
	virtual void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomeThing();
	}
};

// 咖啡
class Coffee: public AbstractDrinking {
public:
	// 煮水
	virtual void Boil() { cout << "煮自来水" << endl; }
	// 冲泡
	virtual void Brew() { cout << "冲泡雀巢咖啡" << endl; }
	// 加入辅料
	virtual void PutSomeThing() { cout << "加入糖和牛奶" << endl; }
};

// 茶
class Tea : public AbstractDrinking {
public:
	// 冲泡
	virtual void Brew() { cout << "冲泡碧螺春" << endl; }
	// 加入辅料
	virtual void PutSomeThing() { cout << "加入枸杞" << endl; }
};

// 制作函数
void doWork(AbstractDrinking * ad) { 
	ad->makeDrink();
	delete ad;
}

// 执行的实参 类型不同，执行的方法不同。
void test25() {
	doWork(new Coffee);
	cout << "--------------------------" << endl;
	doWork(new Tea);
}