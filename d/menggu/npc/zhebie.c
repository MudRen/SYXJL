//zhebie.c
inherit NPC;
void create ()
 {            
                set_name("�ܱ�", ({"zhebie", "zhe"}) );
              set("title", "�����");
              set("gender", "����");
              set("age", 27);
              set("str", 28);
              set("int", 15);
              set("long",

"�����е���ģ����������Գ�Ӣ��֮�����ֳ�һ���𹭣�
��������ľ��ĵ�һ������ܱ��ܱ������������֮��
��Ϊ�������������˶������ܱ𣬷�����������������\n");
              set("combat_exp", 150000);
              set("attitude", "heroism");
              set("force", 1500);
              set("max_force",1500);
              set("force_factor", 10);
              set_skill("sword", 90);
              set_skill("unarmed", 90);
              set_skill("dodge", 90);
              set_skill("force", 90);

          set("inquiry", ([
               "����":"���������ã��Ѿ�����ľ��ͻ���˹��������������������ء�\n"
              ]));
           setup();
}
