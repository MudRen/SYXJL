inherit NPC;
void create()
{
        set_name("��ľ��", ({"teimuzhen", "tie" }));
        set("title", "�ɼ�˼��" );
                    set("gender", "����");
                   set("age", 48 );
                   set("str", 25 );
                   set("int", 16 );
                   set("long",                   
"������ĸߴ�ͷ���������������һ�Ժ�ɫ�ĺ��ӣ�˫
 Ŀһת���������䡣�������ɹŲ����������ľ�档\n" );
                    set("combat_exp", 130000 );
                    set("attitude", "heroism" );
                    set("force", 1000 );
                    set("max_force", 1000 );
                    set("force_factor", 0 );
                    set_skill("parry", 80 );
                    set_skill("dodge", 70 );
                    set_skill("force", 70 );
                    set_skill("sword", 80 );                           
                    set_skill("unarmed", 80 );
                    set("inquiry", ( [
                           "name": "�Ҿ�����ľ�档\n"                                                                                                                                                                                                              
        ]));
           setup();
}
