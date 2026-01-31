#include "./headers/StripManager.h"

StripManager& StripManager::getInstance()
{
	static StripManager instance;
	return instance;
}
