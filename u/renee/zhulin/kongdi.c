// renee

#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_lingwu(string arg);

void create()
{
    set("short", GRN "���ֿյ�"NOR);
    set("long", @LONG
�紵�����ַ������������ɣ��������ܳ������� ��˵�����˾���
��������������ϸһ�����������в��ٽ��ۣ������ﲻԶ�м�С�ݡ�
LONG
	);
	
	set("exits", ([
	"northwest"      : __DIR__"zhulin14",
]) );


 	setup();

}

void init()
{
        add_action("do_lingwu", "kan");
}

int do_lingwu(string arg)
{
        object me;
        me = this_player();
	  if ( !arg || arg != "jianhen" )
        return notify_fail("��������ʲô! \n");
	  
 	  if( (int)me->query_skill("taiji-jian", 1) < 200 )
                return notify_fail("���̫������������죬�޷��������һ����\n");

	  if(me->query_temp("wudang/quest1")==1)
	  {
        me->set("wudang/guizhen",1);
        message_vision("$N�����˰��죬Խ��Խ���������·𿴵���������������\n" 
                        "ÿһ�����۶�������̫�����о��衣������ˡ�����һ�����ľ���\n" , me);
        return 1;
         }
        else
         {
        tell_object(me,"What ?\n" );
        return 1;
         }
}
