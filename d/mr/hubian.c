#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long",@long
�׻�˵ : ��������, �����պ����������Ǵ��������̫���� �����̲���Ư
��һҶҶ��С��, һ�����ö���С�������ź��ϵ���粻ʱƯ����Ķ��С�
long);
         set("outdoors","mr");      
         set("exits", ([
             "east" : __DIR__"hubian1",
      "west" : "/d/taishan/yidao4",
]));
         set("coor/x",80);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",80);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",80);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",80);
	set("coor/y",20);
	set("coor/z",0);
	setup();
         replace_program(ROOM);
}
