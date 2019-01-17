// sgangfyshi.c �ͷ�ʹ

#include <ansi.h>
#include "/quest/quest.h"
inherit F_UNIQUE;
inherit NPC;

int ask_me();

void create()
{
       seteuid(getuid());
	set_name("�ڰ���", ({ "heibai zi", "zi" }) );
         set("nickname", HIM "����" NOR);
	set("gender", "����");
	set("age", 48);
	set("long",
		"ֻ������Ȼ���������۶��룬��ò��񳣬\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
	set("max_jing", 300);
	set("jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("strike",60);
	set_skill("wuji-shengong",60);
	set_skill("fanyun-zhang",60);
	set_skill("bugui-bufa",60);

	
	map_skill("force", "wuji-shengong");
	map_skill("dodge", "bugui-bufa");
	map_skill("parry", "fanyun-zhang");
	map_skill("strike", "fanyun-zhang");

	
	create_family("ɱ��¥", 2, "ɱ��");
	set("title","ɱ��¥�ͷ�ʹ");

            set("no_get",1);
	set("inquiry", ([
                "ְλ" : (: ask_me :),
	]));

	setup();

}

int ask_me()
{
        object me;
	mapping fam;
	me=this_player();
        fam = me->query("family");

	if ( ((string)me->query("family/family_name") == "" ) || 
		( (string)me->query("family/family_name") != "" &&
		(string)me->query("family/family_name") != "ɱ��¥" ) )
	{
		message_vision("�ڰ��Ӷ�$N˵�����㲻�Ǳ�����ˣ������������ܸ����㣿\n", me);
		return 1;
	}

	if ( (int)me->query("combat_exp") < 100000 )
	{
		message_vision("�ڰ��Ӷ�$N˵������Ա���Ĺ��׻��������Ժ���˵�ɡ�\n", me);
		return 1;
	}
	message_vision("�ڰ��Ӷ�$N˵������Ա���Ĺ��ײ�С�����ھ�������������Ļ����ɡ�\n", me);
	if ( (int)me->query("combat_exp") >= 500000 )
	{
                me->set("title", "ɱ��¥����ɱ��");
		return 1;
	}
	if ( (int)me->query("combat_exp") >= 400000 )
	{
               me->set("title","ɱ��¥����ɱ��");
		return 1;
	}
	if ( (int)me->query("combat_exp") >= 300000 )
	{
                me->set("title","ɱ��¥����ɱ��");
		return 1;
	}
	if ( (int)me->query("combat_exp") >= 200000 )
	{
                me->set("title","ɱ��¥����ɱ��");
		return 1;
	}
	if ( (int)me->query("combat_exp") >= 100000 )
	{
                me->set("title","ɱ��¥����ɱ��");
		return 1;
	}
	return 1;
}

