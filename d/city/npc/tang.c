// tang.c ���ϰ� 

#include <ansi.h>

inherit F_PAWN;

void create()
{
        set_name("���", ({ "tang nan", "tang" }));
        set("title", "�����ϰ�");
        set("shen_type", 0);
        set("no_get",1);
        set("gender", "����");
//        set_max_encumbrance(100000000);
        set("str",1000000000);
        set("age", 35);
        set("long",
                "��˵������Ĵ��Ƽҵĺ����\n");
        set("no_get_from", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        
        setup();
   this_player()->carry_object("/clone/misc/cloth")->wear();
}


