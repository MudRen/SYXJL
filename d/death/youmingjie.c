inherit ROOM; 
#include <ansi.h>
int num_of_killer;
string call_killer();

void create() 
{ 
        set("short", "��ڤ��");
        set("long", @LONG

��ڤ�磬��������ô��ۺ���ߵ��������ˡ��Ĵ�������Ũ�������
��ʲôҲ������������и������������ֵĹ����Χ�ƺ���һ˫˫
�۾������㿴�������˼�������������б����һ��ʯ����shibei����
����æ������ȥ��������֡�
LONG);
       set("no_clean_up", 0);
       set("item_desc", ([
        "shibei" : (: call_killer :),
    ]));

       set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"youmingdian",
  "up" : __DIR__"road3",
]));
       
       setup();
        reset();
}

void reset()
{
        ::reset();
        num_of_killer = 5;
}

string call_killer()
{
        object ob;
        if (num_of_killer == 0) 
        return "ʯ����д�ż���Ѫ��Ĵ��֣�
"HIR"        ۺ �� �� �� �� ڤ �� �� ����"NOR"
��Ȼ����ñ����ƺ��нŲ�����������Ȼ��ͷһ��������
ʲôҲû���֣�ԭ�����龪һ����\n";
        num_of_killer --;
        ob = new(__DIR__"npc/ghost");
        ob->move("/d/death/youmingjie");
        return "ʯ����д�ż���Ѫ��Ĵ��֣�
"HIR"        ۺ �� �� �� �� ڤ �� �� ����"NOR"
��Ȼ����ñ����ƺ��нŲ�����������Ȼ��ͷһ��������\n";
}
