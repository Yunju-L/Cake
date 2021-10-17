#include <bangtal>
using namespace bangtal;


void egg(ObjectPtr egg_broken, bool egg_state, int* egg_count, ObjectPtr egg_basket, ObjectPtr whisk) {
	egg_broken->show();
	egg_state = false;
	*egg_count -= 1;

	if (*egg_count == 0) {
		egg_basket->hide();
		egg_broken->hide();
		whisk->show();
	}

}

void oven_complete(ObjectPtr oven, ObjectPtr cake_pre, ObjectPtr cake, ObjectPtr degree, ObjectPtr time, ObjectPtr prev, ObjectPtr next) {
	showMessage("완료!");
	oven->hide();
	cake_pre->hide();
	degree->hide();
	time->hide();
	cake->show();
	prev->show();
	next->show();

}



//문제) 비밀번호를 찾기 위해 스위치를 눌러 거실이 어두워지면, object가 상대적으로 밝아보인다.

int main() {

	//배경
	auto scene1 = Scene::create("거실", "Images/거실.png");
	auto scene2 = Scene::create("부엌", "Images/부엌.png");


	//거실 물건
	auto phone = Object::create("Images/휴대폰 켜짐.png", scene1, 700, 190);
	phone->setScale(0.2f);
	auto light = Object::create("Images/스위치.png", scene1, 947, 455);
	auto password = Object::create("Images/비밀번호.png", scene1, 75, 550, false);
	password->setScale(0.7f);
	auto box = Object::create("Images/금고 닫힘.png", scene1, 125, 259);
	auto message = Object::create("Images/문자.png", scene1, 500, 10, false);
	message->setScale(1.4f);
	auto to_scene2 = Object::create("Images/부엌으로.png", scene1, 0, 0);
	auto recipe1 = Object::create("Images/레시피.png", scene1, 420, 100, false);

	//부엌 물건
	auto to_scene1 = Object::create("Images/거실로.png", scene2, 0, 0);
	auto recipe_wall = Object::create("Images/벽 레시피.png", scene2, 100, 450, false);
	recipe_wall->setScale(0.1f);
	auto bowl = Object::create("Images/볼.png", scene2, 400, 80, false);
	auto egg1 = Object::create("Images/계란.png", scene2, 920, 350, false);
	auto egg2 = Object::create("Images/계란.png", scene2, 995, 350, false);
	auto egg3 = Object::create("Images/계란.png", scene2, 1070, 350, false);
	auto egg1_ = Object::create("Images/계란 노른자1.png", scene2, 480, 188, false);
	auto egg2_ = Object::create("Images/계란 노른자2.png", scene2, 632, 192, false);
	auto egg3_ = Object::create("Images/계란 노른자3.png", scene2, 645, 200, false);
	auto egg_basket = Object::create("Images/계란 바구니.png", scene2, 910, 340, false);
	auto egg_broken = Object::create("Images/깨진 계란.png", scene2, 560, 500, false);
	auto egg_beaten = Object::create("Images/계란물.png", scene2, 450, 185, false);

	auto flour1 = Object::create("Images/박력분.png", scene2, 920, 320, false);
	auto flour2 = Object::create("Images/중력분.png", scene2, 1060, 320, false);
	auto flour = Object::create("Images/밀가루.png", scene2, 448, 184, false);
	auto flour_dough = Object::create("Images/밀가루 반죽.png", scene2, 440, 181, false);

	auto choice = Object::create("Images/선택.png", scene2, 500, 200, false);

	auto sugar = Object::create("Images/설탕통.png", scene2, 150, 350, false);
	auto salt = Object::create("Images/소금통.png", scene2, 250, 350, false);
	auto chili = Object::create("Images/고춧가루통.png", scene2, 920, 350, false);
	auto butter = Object::create("Images/버터통.png", scene2, 1020, 340, false);
	auto sugar_ = Object::create("Images/설탕.png", scene2, 480, 240, false);
	auto salt_ = Object::create("Images/소금.png", scene2, 640, 240, false);
	auto chili_ = Object::create("Images/고춧가루.png", scene2, 610, 190, false);
	auto butter_ = Object::create("Images/버터.png", scene2, 580, 260, false);
	auto whisk = Object::create("Images/거품기.png", scene2, 600, 300, false);

	auto oven = Object::create("Images/오븐.png", scene2, 200, 50, false);
	auto degree = Object::create("Images/버튼.png", scene2, 300, 400, false);
	auto time = Object::create("Images/버튼.png", scene2, 800, 400, false);
	auto cake_pre = Object::create("Images/케이크 반죽.png", scene2, 390, 200, false);
	auto cake = Object::create("Images/케이크.png", scene2, 370, 60, false);
	auto cream = Object::create("Images/생크림 선택.png", scene2, 1000, 500, false);
	auto cream_choco = Object::create("Images/초코크림 선택.png", scene2, 1000, 300, false);
	auto cream_berry = Object::create("Images/딸기크림 선택.png", scene2, 1000, 100, false);

	auto deco_cream = Object::create("Images/크림 선택.png", scene2, 50, 500, false);
	auto deco_blueberry = Object::create("Images/블루베리 선택.png", scene2, 50, 300, false);
	auto deco_strawberry = Object::create("Images/딸기 선택.png", scene2, 50, 100, false);
	auto deco_cherry = Object::create("Images/체리 선택.png", scene2, 1000, 500, false);
	auto deco_candle = Object::create("Images/초 선택.png", scene2, 1000, 300, false);
	auto deco_choco = Object::create("Images/초코 선택.png", scene2, 1000, 100, false);
	auto deco_choco_ = Object::create("Images/초코.png", scene2, 375, 90, false);
	auto deco_cream_ = Object::create("Images/크림.png", scene2, 350, 215, false);
	auto deco_fruit = Object::create("Images/딸기.png", scene2, 600, 360, false);
	auto deco_candle_ = Object::create("Images/초.png", scene2, 445, 300, false);

	auto done = Object::create("Images/완료.png", scene2, 550, 570, false);

	auto prev = Object::create("Images/이전으로.png", scene2, 50, 200, false);
	auto next = Object::create("Images/다음으로.png", scene2, 950, 200, false);


	auto recipe2 = Object::create("Images/레시피.png", scene2, 430, 100, false);



	auto message_check = 0;
	auto light_state = 1; //0:꺼짐 1: 켜짐
	auto box_state = 0; //0:닫힘 1: 열림
	auto stage = 1;
	auto recipe_shown = false; //안 보임
	auto egg_state = true; //안 깨진 상태
	auto egg_count = 3;
	auto flour_choice = 0; //0: 선택 안 함 1: 옳은 선택 -1: 틀린 선택
	auto sugar_state = 0;
	auto salt_state = 0;
	auto chili_state = 0;
	auto butter_state = 0;
	//auto something = 0; //0: 선택 안 함 1: 고춧가루 선택 -1 : 넣어야 할 걸 안 넣음
	auto oven_check = 0;
	auto deco_cream_state = 0;
	auto deco_candle_state = 0;
	auto deco_choco_state = 0;
	auto deco_strawberry_state = 0;
	auto deco_blueberry_state = 0;
	auto deco_cherry_state = 0;

	//***********************************거실***********************************//


	showMessage("하암~ 잘 잤다!!");

	phone->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		message->show();

		if (message_check == 0) {
			showMessage("헉! 케이크를 직접 만들어서 선물해 주기로 한 걸 까맣게 잊고 있었네!\n약속된 시간 전에 얼른 케이크를 만들어야 해!");
			message_check = 1;
			phone->setImage("Images/휴대폰 꺼짐.png");
		}
		else {
			showMessage("얼른 케이크를 만들자!");

		}

		return true;
		});

	message->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		message->hide();
		return true;

		});


	recipe1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		recipe1->pick();
		return true;

		});


	light->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (light_state == 1) {
			scene1->setLight(.2f);
			password->show();
			light_state = 0;
		}
		else {
			scene1->setLight(1.f);
			password->hide();
			light_state = 1;
		}

		return true;
		});


	box->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (box_state == 0) {
			showMessage("금고를 발견했다. 비밀번호가 뭘까?");
			showKeypad("990116", box);

		}
		else if (box_state == 1 && recipe1->isHanded()) showMessage("빈 금고다.");
		else {
			recipe1->show();
			showMessage("레시피를 찾았다!");
		}
		return true;
		});

	box->setOnKeypadCallback([&](ObjectPtr object)->bool {
		box_state = 1;
		box->setImage("Images/금고 열림.png");
		showMessage("어? 금고에 뭔가가 있다.\n금고를 클릭해서 자세히 살펴보자.");

		return true;
		});

	to_scene2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		scene2->enter();
		return true;

		});


	to_scene1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		scene1->enter();

		return true;

		});





	//***********************************부엌***********************************//


	scene2->setOnEnterCallback([&](ScenePtr scene)->bool {

		if (message_check == 0) {
			showMessage("거실로 가서 휴대폰을 확인하자!");
		}
		else if (message_check == 1 && recipe1->isHanded()) {
			showMessage("케이크 만들기 시작!");
			bowl->show();
			egg1->show();
			egg2->show();
			egg3->show();
			egg_basket->show();
			recipe_wall->show();
			to_scene1->hide();
		}
		else showMessage("아직 요리할 준비가 되지 않은 듯하다.\n 거실을 좀 더 살펴보자.");


		return true;

		});


	//벽에 있는 레시피를 클릭하면 레시피를 볼 수 있다.
	recipe_wall->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (recipe_shown == false) {
			recipe2->show();
			recipe_shown = true;
		}
		else { //레시피를 클릭하면 사라진다.
			recipe2->hide();
			recipe_shown = false;
		}

		return true;

		});


	//큰 레시피를 클릭해도 사라진다.
	recipe2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		recipe2->hide();
		recipe_shown = false;

		return true;
		});


	//***********************************부엌-stage1:달걀 까기***********************************//

	//달걀1
	egg1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		egg1->hide();
		egg1_->show();
		egg(egg_broken, egg_state, &egg_count, egg_basket, whisk);

		return true;
		});


	//달걀2
	egg2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		egg2->hide();
		egg2_->show();
		egg(egg_broken, egg_state, &egg_count, egg_basket, whisk);

		return true;
		});


	//달걀3
	egg3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		egg3->hide();
		egg3_->show();
		egg(egg_broken, egg_state, &egg_count, egg_basket, whisk);

		return true;
		});


	//깨진 달걀을 클릭하면 사라진다.
	egg_broken->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		egg_broken->hide();
		egg_state = true;

		return true;
		});



	//***********************************부엌-stage2:밀가루 고르기***********************************//

	//박력분
	flour1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		flour_choice = 1;
		flour->show();
		choice->show();
		choice->locate(scene2, 940, 570);
		done->show();

		return true;
		});

	//중력분
	flour2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		flour_choice = -1;
		flour->show();
		choice->show();
		choice->locate(scene2, 1080, 570);
		done->show();

		return true;
		});



	//***********************************부엌-stage3:조미료 고르기***********************************//

	sugar->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (sugar_state == 0) {
			sugar_->show();
			sugar_state = 1;
		}
		else {
			sugar_->hide();
			sugar_state = 0;
		}

		return true;
		});

	salt->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (salt_state == 0) {
			salt_->show();
			salt_state = 1;
		}
		else {
			salt_->hide();
			salt_state = 0;
		}

		return true;
		});

	chili->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (chili_state == 0) {
			chili_->show();
			chili_state = 1;
		}
		else {
			chili_->hide();
			chili_state = 0;
		}

		return true;
		});

	butter->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (butter_state == 0) {
			butter_->show();
			butter_state = 1;
		}
		else {
			butter_->hide();
			butter_state = 0;
		}

		return true;
		});

	//***********************************부엌-stage4:오븐에서 굽기***********************************//

	degree->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		showMessage("오븐의 온도를 맞추자");
		showKeypad("180", degree);


		return true;
		});

	degree->setOnKeypadCallback([&](ObjectPtr object)->bool {
		oven_check++;
		if (oven_check == 2) oven_complete(oven, cake_pre, cake, degree, time, prev, next);

		return true;
		});

	time->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


		showMessage("오븐의 시간을 맞추자");
		showKeypad("25", time);

		return true;
		});

	time->setOnKeypadCallback([&](ObjectPtr object)->bool {
		oven_check++;
		if (oven_check == 2) oven_complete(oven, cake_pre, cake, degree, time, prev, next);

		return true;
		});


	//***********************************부엌-stage5:생크림 바르기***********************************//
	cream->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		cake->setImage("Images/생크림.png");

		return true;
		});

	cream_choco->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		cake->setImage("Images/초코 크림.png");

		return true;
		});

	cream_berry->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		cake->setImage("Images/딸기 크림.png");

		return true;
		});



	//***********************************부엌-stage6:케이크 꾸미기***********************************//


	deco_cream->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (deco_cream_state == 0) {
			deco_cream_->show();
			deco_cream_state = 1;
		}
		else {
			deco_cream_->hide();
			deco_cream_state = 0;
		}

		return true;
		});

	deco_strawberry->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {


		if (deco_strawberry_state == 0) {
			deco_fruit->show();
			deco_fruit->setImage("Images/딸기.png");
			deco_strawberry_state = 1;
		}
		else {
			deco_fruit->hide();
			deco_strawberry_state = 0;
		}

		return true;
		});

	deco_blueberry->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (deco_blueberry_state == 0) {
			deco_fruit->show();
			deco_fruit->setImage("Images/블루베리.png");
			deco_blueberry_state = 1;
		}
		else {
			deco_fruit->hide();
			deco_blueberry_state = 0;
		}

		return true;
		});


	deco_cherry->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (deco_cherry_state == 0) {
			deco_fruit->show();
			deco_fruit->setImage("Images/체리.png");
			deco_cherry_state = 1;
		}
		else {
			deco_fruit->hide();
			deco_cherry_state = 0;
		}

		return true;
		});

	deco_candle->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (deco_candle_state == 0) {
			deco_candle_->show();
			deco_candle_state = 1;
		}
		else {
			deco_candle_->hide();
			deco_candle_state = 0;
		}

		return true;
		});


	deco_choco->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (deco_choco_state == 0) {
			deco_choco_->show();
			deco_choco_state = 1;
		}
		else {
			deco_choco_->hide();
			deco_choco_state = 0;
		}

		return true;
		});


	//***********************************거실-stage7:평가***********************************//




	//***********************************공통***********************************//
	done->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (stage == 2) {
			whisk->show();
			flour1->hide();
			flour2->hide();
			choice->hide();

		}
		else if (stage == 3) {
			whisk->show();
			sugar->hide();
			salt->hide();
			chili->hide();
			butter->hide();
		}
		else if (stage == 5) {
			cream->hide();
			cream_choco->hide();
			cream_berry->hide();
			prev->show();
			next->show();

		}
		else if (stage == 6) {
			deco_cream->hide();
			deco_strawberry->hide();
			deco_blueberry->hide();
			deco_cherry->hide();
			deco_candle->hide();
			deco_choco->hide();
			prev->show();
			next->show();
		}
		done->hide();

		return true;
		});

	whisk->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (stage == 1) {
			egg1_->hide();
			egg2_->hide();
			egg3_->hide();
			egg_beaten->show();
		}
		else if (stage == 2) {
			egg_beaten->hide();
			flour->hide();
			flour_dough->show();
			flour1->hide();
		}
		else if (stage == 3) {
			sugar_->hide();
			salt_->hide();
			chili_->hide();
			butter_->hide();
		}
		whisk->hide();
		prev->show();
		next->show();

		return true;


		});

	prev->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (stage == 1) {
			egg1->show();
			egg2->show();
			egg3->show();
			egg_basket->show();
			egg_broken->hide();
			egg_beaten->hide();
			whisk->hide();
			egg_count = 0;
			stage = 1;

		}
		else if (stage == 2) {
			egg_beaten->show();
			flour->hide();
			flour_dough->hide();
			flour1->show();
			flour2->show();
			stage = 2;
		}
		else if (stage == 3) {

		}
		prev->hide();
		next->hide();

		return true;
		});

	next->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (stage == 1) {
			showMessage("어떤 밀가루를 고를까?");
			flour1->show();
			flour2->show();
			egg_basket->hide();
			egg_broken->hide();
			whisk->hide();

			stage = 2;
		}
		else if (stage == 2) {
			showMessage("필요한 재료를 모두 고르자!");
			flour1->hide();
			flour2->hide();
			sugar->show();
			salt->show();
			chili->show();
			butter->show();
			done->show();
			stage = 3;
		}
		else if (stage == 3) {
			showMessage("적절한 온도와 시간로 케이크를 구워보자!");
			oven->show();
			cake_pre->show();
			degree->show();
			time->show();
			bowl->hide();
			flour_dough->hide();
			stage = 4;

		}
		else if (stage == 4) {
			showMessage("어떤 크림을 바를까?");
			cream->show();
			cream_choco->show();
			cream_berry->show();
			done->show();
			stage = 5;
		}
		else if (stage == 5) {
			showMessage("케이크를 꾸미자!");
			deco_cream->show();
			deco_strawberry->show();
			deco_blueberry->show();
			deco_cherry->show();
			deco_candle->show();
			deco_choco->show();
			done->show();
			done->locate(scene2, 520, 50);
			stage = 6;
		}
		else if (stage == 6) {

		}
		prev->hide();
		next->hide();

		return true;
		});

	startGame(scene1);
}