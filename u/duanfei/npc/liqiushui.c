// liqiushui.c ����ˮ
// shilling 97.2

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("����ˮ", ({ "li qiushui", "qiushui","li" }));
       set("title", "��ңʥŮ");
       set("long", 
               "��������ң����ңʥŮ��������Ϊ��ң������һ���ڽ�����\n"
               "�����ܽ��ɣ��������ڽ����в��Ǻܶ���֪��������ʵ����\n"
               "����ȴ�ǡ���������������������\n");
       set("gender", "Ů��");
       set("age", 35);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("str", 40);
       set("int", 40);
       set("con", 40);
       set("dex", 40);
       set("per", 29);
       
       set("max_qi", 5500);
       set("max_jing", 3000);
       set("neili", 3000);
       set("max_neili", 3000);
       set("jingli", 2000);
       set("max_jingli", 2000);
       set("jiali", 100);
       set("combat_exp", 8000000);
       set("score", 200000);

       set_skill("force", 180);
         set_skill("sword", 180);
         set_skill("strike", 180);
       set_skill("beiming-shengong", 180);
       set_skill("dodge", 180);
       set_skill("lingboweibu", 180);
       set_skill("unarmed", 180);
       set_skill("liuyang-zhang", 180);
       set_skill("parry", 180);
       set_skill("blade", 180);
       set_skill("ruyi-dao", 180);
       set_skill("zhemei-shou", 180);
         set_skill("chixin-qingchang-jian", 180);
     set_skill("hand", 180);
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

       create_family("��ң��", 1, "��ңʥŮ");
       set("class", "taoist");

       setup();
}


          

