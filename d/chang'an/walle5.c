// Room: /d/chang'an/walle5.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�����ǳ�ǽ�ڲ��ʯ�ף�����Դ�������ϳ�ǽ����˵����ĳ�ǽ��
�����Բ���������������Ϊ��ǽ�������ܸߣ������Ե�Ҳ�ܶ����Ա߻�
�пɹ��������µ�б�¡�
LONG );
        set("outdoors", "chang'an");
	set("no_clean_up", 0);

	set("exits", ([
		"southup"   : __DIR__"walle7",
		"northdown" : __DIR__"walle3",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if (dir == "southup" )
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->receive_damage("qi",10);
                  if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<21))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	}
	return 1;
}


