// kekexili.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
          set("short", "�ɿ�����ɽ");
          set("long",@long
�ɿ�����ɽ�ֳƿɿ�ϡ��ɽ���ɹ���Ϊ����ɽ������˼������ľ������
�壬���Ӱ��տ���ɽ��ɽ��ƽ���������㲼���ߴ��������Ի�ѩ���������
�����е�ˮ���������⣬�����ϱ������岼�ĺ�����Ϊ��ˮ������ľϡ�裬
���̼��١�
long);
         set("exits",([
                "northwest" : __DIR__"shankou",
                "east" : __DIR__"bayankala",
         ]));

         set("outdoors", "����ɽ��");
         set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",20);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",20);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",20);
	set("coor/x",-160);
	set("coor/y",20);
	set("coor/z",20);
	setup();
         replace_program(ROOM);    
}
