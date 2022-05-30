#include "debug.h"

//b2Vec2 pixelsToWorld(sf::Vector2f)
//{
//
//	return 0;
//}


void draw(b2World& world, float deltaTime) {

	GR::Window wormsWindow(deltaTime);
	wormsWindow.setKeyArguments(sf::Keyboard::A, { 10.0f });
	wormsWindow.setViewBorder(200.0f, 200.0f, 1920.0f, 1080.0f);
	//wormsWindow.setView(0.0f, 0.0f, 400.0f, 400.0f); // view does not fit in viewBorder so view is set to viewBorder by default
	wormsWindow.setZoomSpeed(4.0f);

	std::vector<std::pair<float, float>> vertices{
		{300.0f, 300.0f},
		{700.0f, 300.0f},
		{700.0f, 700.0f},
		{300.0f, 700.0f}
	};

	GR::StaticAnimatedObject obj(deltaTime, vertices, "");
	//Worm* w = new Worm(world, 10, 10);

	b2Vec2 vec;
	sf::Vector2f sf_vec;

	sf::Clock ck;
	ck.restart();
	float global = 0.0f;

	int i = 0;

	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		wormsWindow.setBackGroundColor(200, 200, 200);
		obj.update();
		//obj.translate({ 500.0f, 0.0f });
		//obj.setPosition({ 600.0f, 500.0f });
		//obj.rotate(deltaTime);
		//vec = w->getPosition();

		cout << "x: " << vec.x << " y: " << vec.y << endl;

		sf_vec.x = vec.x * 20;
		sf_vec.y = vec.y * 20;

		i++;

		if (i >= 100)
		{
			i = 0;
			world.Step(1.0f / 30.0f, 6, 2);
		}
		obj.setPosition({ sf_vec.x, sf_vec.y });
		wormsWindow.update();							// 10 is a random value for now
		//std::cout <<"x: "<< wormsWindow.getMouseWorldCoords().x << " y: " << wormsWindow.getMouseWorldCoords().y << std::endl;
		wormsWindow.draw(obj);
		wormsWindow.endDraw();
	}
}


void terminalDraw(b2World& world, float deltaTime)
{


	b2Vec2* v = new b2Vec2[4];
	v[0].Set(-2.0f, 2.0f);
	v[1].Set(2.0f, 2.0f);
	v[2].Set(2.0f, -2.0f);
	v[3].Set(-2.0f, -2.0f);
	//std::vector<Worm*> boxes;
	//Worm* r = new Worm(world, 10, 10);
	b2Vec2 v1(0.0f, 200.0f);
	//cout<<r->body->GetMass()<<endl;
	//boxes.push_back(r);



	int input = 1;
	r->jump();
	Spring s;
	s.bind(&world, r);
	b2Vec2 l(5.0f, 5.0f);

	while (input != 0)
	{
		s.update(l);
		for (int i = 0; i < input; ++i)
		{
			world.Step(1.0f / 30.0f, 6, 2);
		}
		int a = 0;
		for (auto i : boxes)
		{
			//r->putForceToCenter(v1);
			b2Vec2 pos = i->getPosition();
			float angle = i->getAngle();
			r->getShape(0);
			cout << "Obj: " << a << endl;
			cout << "x: " << pos.x << " y: " << pos.y << " angle: " << angle << endl;

			++a;
		}
		cin >> input;
	}


}