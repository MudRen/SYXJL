// shichang  ..angle
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��ʯ��");
        set("long",
"�����Ǹ��ܴ�Ĳ�ʯ������������Ŀ�����������Ѿ����µĴ��
СС����ʯ����ɽ�ԣ�������ʯ����վ�ھ�ʯ���������ô���ʯͷ������
�ܶ���˽�ʯ�鿸�ڼ�������������͡���˵��Щʯͷ����������ɽ����
��������"+HIR+"�������֡�"+NOR+"����ģ�����˵��"+HIR+"�������֡�"+NOR+"������ʦ̫����һ����
�亱�еľ�ɫ���ˣ�\n ");
        set("no_clean_up", 0);
        set("exits", ([
  "northup" : __DIR__"shanlu1", 
  "west" : __DIR__"shichang1",]));
        set("objects", ([
                __DIR__"songqi" : 1,
        ]));
        set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",30);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}


