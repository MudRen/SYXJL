// guojing.c ����

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"����"NOR);
	set("gender", "����");
	set("age", 25);
	set("long", 
		"�������˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ���������\n"
		"�����߹֡�ȫ�������ڵ���������ؤ�����߹��͡�����ͯ����\n"
		"��ͨ���˵�ͽ�ܣ���������书��\n"
		"������һ����ɫ���ۣ���̬���࣬�غ����Ŀ��͸��һ������\n"
		"���˲��ɵò���һ������֮�顣\n");
 	set("attitude", "peaceful");
	
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set("per", 22);

	set("chat_chance", 1);
	set("chat_msg", ({
		"����̾�˿����������ɹű��ù��������£�һ�����ٳ���ƣ��ض��ֲ�����ߣ���....\n",
		"����˵���������ݹ���������֪�ɺã����һ��Ҫ�ش�Įȥ��������\n",
		(: random_move :),
	}));

	set("inquiry", ([
		"����" : "�ض����ҵİ��ޣ�������������\n",
		"ؤ��" : "����������������\n",
		"��ʦ" : "�����ɹ���Χ��������������������ͽ����\n",
	]));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	
	set("combat_exp", 1800000);
	set("score", 200000);
	 
	set_skill("force", 250);                // �����ڹ�
	set_skill("huntian-qigong", 230);       // ��������
	set_skill("unarmed", 220);		// ����ȭ��
	set_skill("xianglong-zhang", 200);	// ����ʮ����
	set_skill("dodge", 200);                // ��������
	set_skill("xiaoyaoyou", 180);            // ��ң��
	set_skill("parry", 220);                // �����м�
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	
	setup();
	
   this_player()->carry_object("/clone/misc/cloth")->wear();
}
