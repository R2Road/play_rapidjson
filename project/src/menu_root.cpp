#include "Menu_Root.h"

#include <string>

#include "r2tm/r2tm_MenuProcessor.h"
#include "r2tm/r2tm_VersionInfo.h"

#include "test/menu_rapidjson.h"

r2tm::TitleFunctionT Menu_Root::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
				std::string( "Menu Root" )
			+	" | <" + r2tm::VersionInfo.String4Version + ">"
		;
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT Menu_Root::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_Root::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddMenu( 'a', Menu_RapidJson() );


		
		mp->AddSplit();



		mp->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2tm::eDoLeaveAction
			{
				return r2tm::eDoLeaveAction::Exit;
			}
		);
	};
}