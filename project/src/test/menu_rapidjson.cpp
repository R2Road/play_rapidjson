#include "Menu_RapidJson.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test_rapidjson.h"

#include "menu_root.h"

r2tm::TitleFunctionT Menu_RapidJson::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Rapidjson";
	};
}
r2tm::DescriptionFunctionT Menu_RapidJson::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return
					"> Inprogress : ..."
			"\n"	"> ...";
	};
}
r2tm::WriteFunctionT Menu_RapidJson::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_rapidjson::Basic() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}