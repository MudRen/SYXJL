inherit NPC;
void create()
{ 
       set_name("������", ({"boershu", "shu" }));
        set("title", "��Į�Ľ�-����" );
                    set("gender", "����");
                   set("age", 38 );
                   set("str", 27 );
                   set("int", 19 );
                   set("long",                   

"ֻ����ǰ������Ŀ��࣬Ŀ����ӥ��һ������֮����
 �����Ǵ�Į�Ľ�֮һ�Ĳ����ࡣ����ս������λ����
 ս���Ľ��죬ͬʱҲ����ľ�������������飬��ľ��
 ��֮Ϊӥצ������˵��������ӥ��צһ����Ҫ��\n");
                    set("combat_exp", 200000 );
                    set("attitude", "heroism" );
                    set("force", 1600 );
                    set("max_force", 1600 );
                    set("force_factor", 10 );
                    set_skill("parry", 130 );
                    set_skill("dodge", 130 );
                    set_skill("force", 120 );
                    set_skill("sword", 120 );                           
                    set_skill("unarmed", 130 );
                    set("inquiry", ( [
                           "��ľ��": "������Զ����󺺣���ԭ�ϵĳɼ�˼�����ɼ�˼�����ɼ�˼����\n"
                    ] ) );
            setup();
}
