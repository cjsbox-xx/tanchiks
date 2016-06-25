#pragma once
#include "GameContent.h"
#include "GameLogic.h"

class GameWorld : public Layer
{
public:
	static const std::string MAIN_LAYER;

	virtual bool init();

	virtual void initLogic(GameLogic *logic);
	virtual void initContent(GameContent *content);
	virtual void startWorld();

	Layer *getLayerByName(std::string name);
	void addLayer(std::string name, Layer *layer);
protected:
	std::map<std::string, Layer*> _layers;
	GameContent *_content;
	GameLogic *_gameLogic;
};
