// �������
// by csy

#include <ansi.h>

inherit NPC;
#include "/quest/quest.h"
void create()
{
        set_name("�������", ({ "saxi huofo", "huofo" }));
        set("long",@LONG
���������ѩɽ���е��ĸ�ɮ���Է��о�����о���
����һ����ɫ���ģ�ͷ��ɮñ��һ��������˼�����ӡ�
������������쵽ʦ�ŵ�����
LONG
        );
        set("title", HIY "���" NOR);
        set("gender", "����");
        set("nickname", HIC "�����ܹ�" NOR);
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2500);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1200000);
        set("score", 100000);

        set_skill("mizong-xinfa", 120);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 100);
        set_skill("dodge", 120);
        set_skill("shenkong-xing", 100);
        set_skill("unarmed", 120);
        set_skill("yujiamu-quan", 100);
        set_skill("parry", 120);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 100);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");


        create_family("ѩɽ��", 3, "���");
        set("class", "bonze");

        setup();

        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
         add_money("gold",5);
}

