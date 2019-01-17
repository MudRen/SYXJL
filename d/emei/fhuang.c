#include <ansi.h>

inherit ROOM;

int do_tui(string);
void init();

void create()
{
	set("short", "���̨");
	set("long", @LONG
������Ƿ��̨�ˣ��������ľ�ߴ�ï�ܣ��������˺�ϡ�٣�û����
���ӵ��������Եú��ľ���һȺ��Գ�ڴ���֮��������Ԯ��ȴ��һͷ��Գ
 վ��һ���ʯͷ��צ���������������ѡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"bgsgate",
           ]));
	set("objects",([
             __DIR__"npc/baiyuan" : 1,
              ]));  

        set("item_desc", ([
            "stone" : "һ����صĴ�ʯͷ����֪���ܲ����ƶ���.\n",
      ]));
	set("coor/x",-70);
	set("coor/y",-50);
	set("coor/z",20);
	set("coor/x",-70);
	set("coor/y",-50);
	set("coor/z",20);
	set("coor/x",-70);
	set("coor/y",-50);
	set("coor/z",20);
	setup();
}

void init()
{
  add_action("do_tui","tui");
}                             

int do_tui( string arg )
{ 
  object me = this_player();
  object ob; 
  if( !arg || arg != "stone" )
    return notify_fail("��Ҫ��ʲô��\n");
  if(!(me->query_temp("tui")) || me->query_temp("tui") == 0)
    return notify_fail("������Ҫ�ƵĶ�������\n");
  if( me->query("max_neili") < 400 )
    return notify_fail("�����˰��죬��ʯ��һ��������\n"); 
  me->delete_temp("tui");
  say(GRN"ʯ���¡¡�Ĺ���һ�ߣ�¶��һ����Ѩ��\n�Ӷ�������һͷ��Գ�������Աߵİ�Գһ���Х�������ˡ�\n");
  say("$n���ں�������˽�ȥ��\n"NOR,me);
  ob = present("baiyuan", environment(me) );
  destruct(ob);
  me->move(__DIR__"cave");
  return 1; 
}
