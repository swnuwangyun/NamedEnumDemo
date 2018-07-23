// NamedEnumDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//-------------------------------------------------------------------------------------------------------------
class SettingsDialogUglyWarning
{
public:
	enum kTabIndex
	{
		TabDevice,
		TabAnchor
	};

	void onDeviceButtonClick()
	{
		this->reloadTabUI(kTabIndex::TabDevice);
	}

	void onAnchorButtonClick()
	{
		this->reloadTabUI(kTabIndex::TabAnchor);
	}

	void reloadTabUI(kTabIndex index)
	{
		switch(index)
		{
		case kTabIndex::TabDevice:
			printf("TabDevice clicked\r\n");
			break;
		case kTabIndex::TabAnchor:
			printf("TabAnchor clicked\r\n");
			break;
		}
	}
};

//-------------------------------------------------------------------------------------------------------------
namespace kTabIndex
{
	enum kTabIndex
	{
		TabDevice,
		TabAnchor,
		TabMediaFile,
		TabRtmp
	};
}

class SettingsDialogUsingNamespace
{
public:
	void onDeviceButtonClick()
	{
		this->reloadTabUI(kTabIndex::TabDevice);
	}

	void onAnchorButtonClick()
	{
		this->reloadTabUI(kTabIndex::TabAnchor);
	}

	void reloadTabUI(int index)
	{
		switch(index)
		{
		case kTabIndex::TabDevice:
			printf("TabDevice clicked\r\n");
			break;
		case kTabIndex::TabAnchor:
			printf("TabAnchor clicked\r\n");
			break;
		}
	}
};

//-------------------------------------------------------------------------------------------------------------
class SettingsDialogPerfect
{
public:
	struct kTabIndex{enum __vt{
		TabDevice,
		TabAnchor,
		TabMediaFile,
		TabRtmp
	} __v;kTabIndex(kTabIndex::__vt a){__v = a;}operator __vt(){return __v;}};

	void onDeviceButtonClick()
	{
		this->reloadTabUI(kTabIndex::TabDevice);
	}

	void onAnchorButtonClick()
	{
		this->reloadTabUI(kTabIndex::TabAnchor);
	}

	void reloadTabUI(kTabIndex index)
	{
		switch(index)
		{
		case kTabIndex::TabDevice:
			printf("TabDevice clicked\r\n");
			break;
		case kTabIndex::TabAnchor:
			printf("TabAnchor clicked\r\n");
			break;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	{
		SettingsDialogUglyWarning dialog;
		dialog.onDeviceButtonClick();
		dialog.onAnchorButtonClick();
	}

	{
		SettingsDialogUsingNamespace dialog;
		dialog.onDeviceButtonClick();
		dialog.onAnchorButtonClick();
	}

	{
		SettingsDialogPerfect dialog;
		dialog.onDeviceButtonClick();
		dialog.onAnchorButtonClick();
	}
	
	while(true);

	return 0;
}