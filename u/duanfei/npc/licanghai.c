// licanghai.c ��׺�
// shilling 97.2

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("��׺�", ({ "li canghai", "canghai","li" }));
       set("title", "��ң����");
       set("long", 
               "��������ң����ң���ӡ�������Ϊ��ң������һ���ڽ�����\n"
               "�����ܽ��ɣ��������ڽ����в��Ǻܶ���֪��������ʵ����\n"
               "����ȴ�ǡ�������������������ϼ��\n");
       set("gender", "Ů��");
       set("age", 35);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("str", 40);
       set("int", 40);
       set("con", 40);
       set("dex", 40);
       set("per", 40);
       
       set("max_qi", 5500);
       set("max_jing", 3000);
       set("neili", 3000);
       set("max_neili", 3000);
       set("jingli", 2000);
       set("max_jingli", 2000);
       set("jiali", 100);
       set("combat_exp", 10000000);
       set("score", 200000);

       set_skill("force", 200);
         set_skill("sword", 200);
         set_skill("strike", 200);
       set_skill("beiming-shengong", 200);
       set_skill("dodge", 200);
       set_skill("lingboweibu", 200);
       set_skill("unarmed", 200);
       set_skill("liuyang-zhang", 180);
       set_skill("parry", 200);
       set_skill("blade", 200);
       set_skill("ruyi-dao", 180);
       set_skill("zhemei-shou", 200);
         set_skill("chixin-qingchang-jian", 200);
     set_skill("hand", 200);
       set_skill("literate", 120);

       map_skill("force", "beiming-shengong");
       map_skill("dodge", "lingboweibu");
       map_skill("unarmed", "zhemei-shou");
         map_skill("sword", "chixin-qingchang-jian");
     map_skill("strike", "liuyang-zhang");
       map_skill("parry", "ruyi-dao");
       map_skill("blade", "ruyi-dao");

//     prepare_skill("hand","zhemei-shou");
//     prepare_skill("strike","liuyang-zhang");

       create_family("��ң��", 1, "��ң����");
       set("class", "taoist");

       setup();
}


          

