#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������Ƕ���ɽ�����������֡���ï�ܵĴ������¶�������ֵ�һ�ǣ�
ȷ����һ�֡�����������һ�塱�ĸо�����������Ȼ����Ҳ�ܼ�ª������
���࣬�ǲε��߾��޵ĺõط���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"westdown" : __DIR__"qingyin",
	"east" : __DIR__"xiangfang",
]));
        set("no_clean_up", 0);
        create_door("east", "ľ��", "west", DOOR_CLOSED);
        set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",100);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",100);
	setup();
        replace_program(ROOM);
}
