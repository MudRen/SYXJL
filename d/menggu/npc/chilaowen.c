inherit NPC;
void create()
{
        set_name("������", ({"chilaowen", "wen" }));
        set("title", "��Į�Ľ�-����" );
                    set("gender", "����");
                   set("age", 36 );
                   set("str", 29 );
                   set("int", 15 );
                   set("long",                   

"��������Ǵ�Į�Ľ�����С�ģ�Ҳ����뺷�ġ�ֻ������
 �����ֶ��ǵ��̣������Ѫ������������η��������ľ��
 ���ѣ�������������ľ���������\n" );
                    set("combat_exp", 200000 );
                    set("attitude", "heroism" );
                    set("force", 1700 );
                    set("max_force", 1700 );
                    set("force_factor", 10 );
                    set_skill("parry", 140 );
                    set_skill("dodge", 130 );
                    set_skill("force", 120 );
                    set_skill("sword", 120 );                           
                    set_skill("unarmed", 140 );
                    set("inquiry", ( [
                           "��ľ��": "ϣ��������ͳһ�ɹţ����������\n"                                                                                                                                                                                                              
        ]));
              setup();
}
