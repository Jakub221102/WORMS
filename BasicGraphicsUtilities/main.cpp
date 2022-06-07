#pragma once
#include <iostream>
#include <array>
#include <vector>
#include "SFML/Graphics.hpp"
#include "box2d.h"				// usun
#include "input_manager.h"
#include "memory"

#include "cyclic_singly_linked_list.h"
#include "window.h"
#include "static_animated_object.h"
#include "static_object_relative.h"
#include "dynamic_game_object.h"
#include "static_physical_object.h"
#include "static_animated_relative_object.h"
#include "worm.h"

float deltaTime;

int main() {
	GR::Window wormsWindow(deltaTime);
	GR::Text tekst("ala ma kota");
	tekst.setPosition(600.0f, 600.0f);
	tekst.setRelativeTranslation(-45.0f, -45.0f);
	tekst.setColor(255, 0, 0);
	tekst.setCharackterSize(40);
	//wormsWindow.setFramesPerSecond(60);
	wormsWindow.setKeyArguments(sf::Keyboard::A, { 10.0f });
	wormsWindow.setViewBorder(0, 0.0f, 1920.0f, 1080.0f);
	//wormsWindow.setView(0, 0.0f, 1920.0f, 1080.0f);
	wormsWindow.setView(960.0f, 540.0f, 960.0f, 540.0f); // view does not fit in viewBorder so view is set to viewBorder by default
	wormsWindow.setZoomSpeed(1.0f);


	// object vector initialization end at 440 line

	std::vector<std::pair<float, float>> vertices_background{
		{960.0f, 540.0f},
		{1920.0f, 540.0f},
		{1920.0f, 1080.0f},
		{960.0f, 1080.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm1s{
		{1587.0f, 844.0f},
		{1602.0f, 844.0f},
		{1602.0f, 864.0f},
		{1587.0f, 864.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm2s{
		{1365.0f, 770.0f},
		{1380.0f, 770.0f},
		{1380.0f, 790.0f},
		{1365.0f, 790.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm3s{
		{1537.0f, 770.0f},
		{1552.0f, 770.0f},
		{1552.0f, 790.0f},
		{1537.0f, 790.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm1g{
		{1731.0f, 748.0f},
		{1746.0f, 748.0f},
		{1746.0f, 768.0f},
		{1731.0f, 768.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm2g{
		{1777.0f, 898.0f},
		{1792.0f, 898.0f},
		{1792.0f, 918.0f},
		{1777.0f, 918.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm3g{
		{1544.0f, 1003.0f},
		{1559.0f, 1003.0f},
		{1559.0f, 1023.0f},
		{1544.0f, 1023.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm1b{
		{1275.0f, 1003.0f},
		{1290.0f, 1003.0f},
		{1290.0f, 1023.0f},
		{1275.0f, 1023.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm2b{
		{1367.0f, 898.0f},
		{1382.0f, 898.0f},
		{1382.0f, 918.0f},
		{1367.0f, 918.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm3b{
		{1136.0f, 925.0f},
		{1151.0f, 925.0f},
		{1151.0f, 945.0f},
		{1136.0f, 945.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm1p{
		{1095.0f, 816.0f},
		{1110.0f, 816.0f},
		{1110.0f, 836.0f},
		{1095.0f, 836.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm2p{
		{1235.0f, 842.0f},
		{1250.0f, 842.0f},
		{1250.0f, 862.0f},
		{1235.0f, 862.0f}
	};

	std::vector<std::pair<float, float>> vertices_worm3p{
		{1195.0f, 763.0f},
		{1210.0f, 763.0f},
		{1210.0f, 783.0f},
		{1195.0f, 783.0f}
	};


	//FIRST ISLAND


	std::vector<std::pair<float, float>> vertices_hitbox1{
		{1121.17f, 1050.0f},
		{1667.35f, 1050.0f},
		{1652.18f, 1077.0f},
		{1106.0f, 1077.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox2{
		{1106.0f, 1023.0f},
		{1652.35f, 1023.0f},
		{1667.18f, 1050.0f},
		{1121.0f, 1050.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox3{
		{1121.17f, 997.0f},
		{1242.54f, 997.0f},
		{1257.73f, 1023.0f},
		{1106.0f, 1023.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox4{
		{1212.22f, 997.0f},
		{1121.17f, 997.0f},
		{1106.0f, 971.0f},
		{1197.05f, 971.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox5{
		{1106.0f, 971.0f},
		{1121.17f, 945.0f},
		{1151.51f, 945.0f},
		{1166.69f, 971.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox6{
		{1288.08f, 1023.0f},
		{1303.25f, 997.0f},
		{1515.65f, 997.0f},
		{1530.83f, 1023.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox7{
		{1333.57f, 997.0f},
		{1348.75f, 971.0f},
		{1470.16f, 971.0f},
		{1485.29f, 997.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox8{
		{1348.75f, 971.0f},
		{1333.57f, 945.0f},
		{1424.6f, 945.0f},
		{1439.78f, 971.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox9{
		{1333.57f, 945.0f},
		{1348.75f, 919.0f},
		{1379.09f, 919.0f},
		{1394.26f, 945.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox10{
		{1561.15f, 1023.0f},
		{1576.32f, 997.0f},
		{1606.66f, 997.0f},
		{1621.84f, 1023.0f},
	};


	//SECOND ISLAND


	std::vector<std::pair<float, float>> vertices_hitbox11{
		{1039.0f, 916.0f},
		{1023.83f, 890.0f},
		{1084.52f, 890.0f},
		{1069.34f, 916.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox12{
		{1221.08f, 916.0f},
		{1205.91f, 890.0f},
		{1266.6f, 890.0f},
		{1251.42f, 916.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox13{
		{1023.83f, 890.0f},
		{1039.0f, 863.0f},
		{1130.03f, 863.0f},
		{1114.86f, 890.0f},
	};

	std::vector<std::pair<float, float>> vertices_hitbox14{
		{1161.39f, 863.0f},
		{1251.42f, 863.0f},
		{1266.6f, 890.0f},
		{1176.57f, 890.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox15{
		{1069.34f, 863.0f},
		{1084.52f, 837.0f},
		{1205.89f, 837.0f},
		{1221.06f, 863.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox16{
		{1114.86f, 837.0f},
		{1130.03f, 811.0f},
		{1221.06f, 811.0f},
		{1205.89f, 837.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox17{
		{1160.37f, 811.0f},
		{1175.55f, 785.0f},
		{1205.89f, 785.0f},
		{1221.06f, 811.0f},

	};


	//THIRD ISLAND


	std::vector<std::pair<float, float>> vertices_hitbox18{
		{1348.17f, 844.0f},
		{1333.0f, 817.0f},
		{1393.69f, 817.0f},
		{1378.51f, 844.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox19{
		{1439.2f, 844.0f},
		{1424.03f, 817.0f},
		{1484.72f, 817.0f},
		{1469.54f, 844.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox20{
		{1530.23f, 844.0f},
		{1515.06f, 817.0f},
		{1575.75f, 817.0f},
		{1560.57f, 844.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox21{
		{1333.0f, 817.0f},
		{1348.17f, 790.0f},
		{1560.57f, 790.0f},
		{1575.75f, 817.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox22{
		{1378.51f, 790.0f},
		{1393.69f, 764.0f},
		{1515.06f, 764.0f},
		{1530.23f, 790.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox23{
		{1424.03f, 764.0f},
		{1439.2f, 738.0f},
		{1469.54f, 738.0f},
		{1484.72f, 764.0f},

	};


	//FOURTH ISLAND (the single tile one)


	std::vector<std::pair<float, float>> vertices_hitbox24{
		{1571.0f, 917.0f},
		{1555.83f, 890.0f},
		{1571.0f, 864.0f},
		{1601.34f, 864.0f},
		{1616.51f, 890.0f},
		{1601.34f, 917.0f}

	};


	//FIFTH ISLAND


	std::vector<std::pair<float, float>> vertices_hitbox25{
		{1806.0f, 1050.0f},
		{1790.83f, 1024.0f},
		{1851.52f, 1024.0f},
		{1836.35f, 1050.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox26{
		{1760.49f, 1024.0f},
		{1745.32f, 998.0f},
		{1836.35f, 998.0f},
		{1851.52f, 1024.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox27{
		{1714.98f, 998.0f},
		{1699.8f, 972.0f},
		{1851.52f, 972.0f},
		{1836.35f, 998.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox28{
		{1669.47f, 972.0f},
		{1654.29f, 945.0f},
		{1897.03f, 945.0f},
		{1881.86f, 972.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox29{
		{1654.29f, 945.0f},
		{1669.47f, 919.0f},
		{1699.8f, 919.0f},
		{1714.98f, 945.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox30{
		{1745.32f, 945.0f},
		{1760.5f, 919.0f},
		{1881.87f, 919.0f},
		{1897.04f, 945.0f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox31{
		{1790.83f, 919.0f},
		{1806.01f, 893.0f},
		{1836.35f, 893.0f},
		{1851.52f, 919.0f},

	};


	//SIXTH ISLAND (the last one)


	std::vector<std::pair<float, float>> vertices_hitbox32{
		{1719.0f, 874.5f},
		{1703.83f, 848.5f},
		{1764.52f, 848.5f},
		{1749.34f, 874.5f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox33{
		{1673.49f, 848.5f},
		{1658.32f, 822.5f},
		{1810.03f, 822.5f},
		{1794.85f, 848.5f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox34{
		{1658.32f, 822.5f},
		{1673.49f, 795.5f},
		{1855.54f, 795.5f},
		{1840.36f, 822.5f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox35{
		{1703.83f, 795.5f},
		{1719.0f, 769.5f},
		{1840.36f, 769.5f},
		{1855.54f, 795.5f},

	};

	std::vector<std::pair<float, float>> vertices_hitbox36{
		{1749.34f, 769.5f},
		{1764.51f, 743.5f},
		{1794.85f, 743.5f},
		{1810.03f, 769.5f},

	};

	std::vector<std::pair<float, float>> vertices_bum{
		{1455.0f, 870.0f},
		{1555.0f, 870.0f},
		{1555.0f, 970.0f},
		{1455.0f, 970.0f},

	};

	std::vector<std::pair<float, float>> vertices_icon{
		{0.0f, 0.0f},
		{2.2 * 56.90f, 0.0f},
		{2.2 * 56.90f, 2.2 * 18.90f},
		{0.0f, 2.2 * 18.90f}
	};

	//Setings of the world like gravity

	b2Vec2 gravity(0.0f, -20.0f);
	b2World world(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(700.0f, -600.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(800.0f, 1.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	//Textures of map

	GR::StaticObject sky(deltaTime, vertices_background, "animacje/niebo.png");
	GR::StaticObject ground(deltaTime, vertices_background, "animacje/ziemia.png");
	GR::StaticAnimatedObject water(deltaTime, vertices_background, "animacje/woda.png");
	GR::StaticAnimatedObject bum(deltaTime, vertices_bum, "animacje/explosion.png");


	//===============================================================================================

	//Creating hitbox of terain objects Vector

	std::vector<std::unique_ptr<GR::StaticPhysicalObject>> terainqueue;

	//FIRST ISLAND

	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox1, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox2, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox3, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox4, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox5, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox6, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox7, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox8, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox9, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox10, "animacje/hitbox.png"));
	
	//SECOND ISLAND

	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox11, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox12, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox13, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox14, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox15, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox16, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox17, "animacje/hitbox.png"));

	//THIRD ISLAND

	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox18, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox19, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox20, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox21, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox22, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox23, "animacje/hitbox.png"));

	//FOURTH ISLAND (the single tile one)

	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox24, "animacje/hitbox.png"));

	//FIFTH ISLAND

	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox25, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox26, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox27, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox28, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox29, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox30, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox31, "animacje/hitbox.png"));

	//SIXTH ISLAND (the last one)

	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox32, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox33, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox34, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox35, "animacje/hitbox.png"));
	terainqueue.push_back(std::make_unique<GR::StaticPhysicalObject>(world, deltaTime, vertices_hitbox36, "animacje/hitbox.png"));
	
	//================================================================================================
	//Creating worms objects Vector

	std::vector<std::unique_ptr<Worm>> wormqueue;
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm1p, "animacje/polfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm1g, "animacje/tzegerfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm1s, "animacje/sovfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm1b, "animacje/britfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm2b, "animacje/britfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm2s, "animacje/sovfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm2g, "animacje/tzegerfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm2p, "animacje/polfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm3p, "animacje/polfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm3g, "animacje/tzegerfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm3s, "animacje/sovfront.png"));
	wormqueue.push_back(std::make_unique<Worm>(world, deltaTime, vertices_worm3b, "animacje/britfront.png"));

	//Creating text objects Vector

	std::vector<std::unique_ptr<GR::Text>> textqueue;
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());
	textqueue.push_back(std::make_unique<GR::Text>());



	//Icons

	GR::RelativeStaticObject icon(deltaTime, vertices_icon, "animacje/wepons_icon.png");
	GR::StaticAnimatedRelativeObject icon1(deltaTime, vertices_icon, "animacje/wepons_icon.png");
	icon1.addAnimation("IDLE", "animacje/polfront.png", 3, 3.0f);
	icon1.setCurrentAnimation("IDLE");
	icon1.attachViewAndZoom(wormsWindow);
	icon1.setRelativeVector({ 373.0f, 130.0f });
	//================================================================================================

	icon.attachViewAndZoom(wormsWindow);
	Worm obj(world, deltaTime, vertices_worm3b, "animacje/sovleftmarch.png");
	icon.setRelativeVector({ 73.0f, 30.0f });
	GR::Text teks;
	teks.setRelativeTranslation(-5.5f, -10.0f);
	teks.setCharackterSize(8);
	teks.setColor(255, 0, 0);
	obj.attachText(teks);
	
	//test worm object

	obj.addAnimation("march", "animacje/sovleftmarch.png", 4, 3.0f);
	obj.setCurrentAnimation("march");
	obj.addKeyBinding(sf::Keyboard::Space, &Worm::jump, InputType::REALTIME);
	obj.setKeyArguments(sf::Keyboard::Space, { 0.0f, 25.0f }, InputType::REALTIME); // pass velocity to jump method
	obj.addKeyBinding(sf::Keyboard::Right, &Worm::move_right, InputType::REALTIME);
	obj.setKeyArguments(sf::Keyboard::Right, { 0.5f, 0.0f }, InputType::REALTIME); // pass velocity to move method
	obj.addKeyBinding(sf::Keyboard::Left, &Worm::move_left, InputType::REALTIME);
	obj.setKeyArguments(sf::Keyboard::Left, { -0.5f, 0.0f }, InputType::REALTIME); // pass velocity to move method
	obj.addKeyBinding(sf::Keyboard::Down, &Worm::move_down, InputType::REALTIME);
	obj.setKeyArguments(sf::Keyboard::Down, { 0.0f, -25.0f }, InputType::REALTIME); // pass velocity to move method
	obj.addKeyBinding(sf::Keyboard::Num1, &Worm::pickWeapon1, InputType::REALTIME);
	obj.addKeyBinding(sf::Keyboard::Num2, &Worm::pickWeapon2, InputType::REALTIME);
	obj.addKeyBinding(sf::Keyboard::Num3, &Worm::pickWeapon3, InputType::REALTIME);

	//seting up worms text

	/*GR::Text teks1;
	teks1.setRelativeTranslation(-5.5f, -10.0f);
	teks1.setCharackterSize(8);
	teks1.setColor(255, 0, 0);
	worm1s.attachText(teks1);*/

	
	//Seting up object animations

	obj.addAnimation("LEFT", "animacje/sovleftmarch.png", 4, 3.0f);
	obj.addAnimation("RIGHT", "animacje/sovrightmarch.png", 4, 3.0f);
	obj.addAnimation("JUMP", "animacje/worm_jump_sov.png", 4, 3.0f);
	obj.setCurrentAnimation("WORM");


	water.addAnimation("WATER", "animacje/woda.png", 4, 2.0f);
	water.setCurrentAnimation("WATER");
	bum.addAnimation("BUM", "animacje/explosion.png", 5, 1.0f);
	bum.setCurrentAnimation("BUM");

	wormqueue[2]->addAnimation("WORM", "animacje/sovfront.png", 3, 4.0f);
	wormqueue[2]->setCurrentAnimation("WORM");
	wormqueue[5]->addAnimation("WORM", "animacje/sovfront.png", 3, 4.0f);
	wormqueue[5]->setCurrentAnimation("WORM");
	wormqueue[10]->addAnimation("WORM", "animacje/sovfront.png", 3, 4.0f);
	wormqueue[10]->setCurrentAnimation("WORM");

	wormqueue[1]->addAnimation("WORM", "animacje/tzegerfront.png", 3, 4.0f);
	wormqueue[1]->setCurrentAnimation("WORM");
	wormqueue[6]->addAnimation("WORM", "animacje/tzegerfront.png", 3, 4.0f);
	wormqueue[6]->setCurrentAnimation("WORM");
	wormqueue[9]->addAnimation("WORM", "animacje/tzegerfront.png", 3, 4.0f);
	wormqueue[9]->setCurrentAnimation("WORM");

	wormqueue[3]->addAnimation("WORM", "animacje/britfront.png", 3, 4.0f);
	wormqueue[3]->setCurrentAnimation("WORM");
	wormqueue[4]->addAnimation("WORM", "animacje/britfront.png", 3, 4.0f);
	wormqueue[4]->setCurrentAnimation("WORM");
	wormqueue[11]->addAnimation("WORM", "britfront.png", 3, 4.0f);
	wormqueue[11]->setCurrentAnimation("WORM");

	wormqueue[0]->addAnimation("WORM", "animacje/polfront.png", 3, 4.0f);
	wormqueue[0]->setCurrentAnimation("WORM");
	wormqueue[7]->addAnimation("WORM", "animacje/polfront.png", 3, 4.0f);
	wormqueue[7]->setCurrentAnimation("WORM");
	wormqueue[8]->addAnimation("WORM", "animacje/polfront.png", 3, 4.0f);
	wormqueue[8]->setCurrentAnimation("WORM");

	//actual game loop

	sf::Clock ck;
	ck.restart();
	//sky.translate({ 500.0f, 0.0f });
	//sky.setPosition({ 0.0f, 0.0f });
	float global = 0.0f;
	//list.addToTail()
	while (!wormsWindow.isDone()) {
		deltaTime = ck.restart().asSeconds();
		wormsWindow.setBackGroundColor(100, 100, 100);

		
	

		water.update();
		//bum.update();

		//Test worm
		auto mouse = wormsWindow.getMouseWorldCoords();
		obj.update(mouse.x, mouse.y);

		//obj.rotate(deltaTime);
		wormsWindow.update();							// 10 is a random value for now
		icon.update();		// NEEDS TO BE AFTER wormsWindow.update() !!!!!!!!!!!!!!!
		icon1.update();
		//std::cout << wormsWindow.getMouseWorldCoords().x << ' ' << wormsWindow.getMouseWorldCoords().y << std::endl;

		//wormsWindow.draw(sky);
		//wormsWindow.draw(ground);

		//Map hitbox

		//FIRST ISLAND


		//Map textures

		wormsWindow.draw(sky);
		wormsWindow.draw(ground);

		//Worms

		wormsWindow.draw(obj);

		wormsWindow.draw(water); //water has to be drawn after the worms

		//wormsWindow.draw(bum);

		//icon needs to be drawn at very end

		wormsWindow.draw(icon);
		wormsWindow.draw(icon1);
		std::cout << icon.getPosition().x << icon.getPosition().y << std::endl;

		wormsWindow.endDraw();
		world.Step(deltaTime, 6, 2);
		world.Step(deltaTime, 6, 2);
	}
	return 0;
}