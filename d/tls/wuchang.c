inherit ROOM;

void create()
{
	set("short", "�䳡����");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����߽��ϻ�
��������ɳ�ӣ�ʮ����ɮ��������ϰ���ա��ϱ��������һ����
����
LONG
	);

	set("exits", ([
		"south" : __DIR__"wuchang2",
		"east" : __DIR__"wuchang3",
		"westup" : __DIR__"doushuai",
		"north" : __DIR__"wuchang4",
	]));

	set("outdoors", "tianlongsi");
	set("objects",([
		__DIR__"npc/saodiseng" : 1,
                __DIR__"npc/gui-yuan" : 1,
	]));
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",20);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",20);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",20);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",20);
	setup();

}

void init()
{
	object me;
	mapping skill_status;
	string *sname;
	int i, level; 
	float exper;

	me = this_player();

	if (wizardp(me)) return;

	exper = to_float(me->query("combat_exp"));

	if ( !(skill_status = me->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper 
		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "literate"
		&& sname[i] != "taoism" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			me->set_skill(sname[i], level);
		}
	}
}



