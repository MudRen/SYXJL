// shitong.c

inherit NPC;

void create()
{
	set_name("��ͯ",({ "shi tong","shi","tong" }) );
        set("gender", "����" );
        set("age", 13);
        set("long", 
            "�һ����ϵ���ͯ���������㿡������Ȼ�������ࡣ\n"+
            "���۾�ȴ�����㲻ͣ�ع�µµ��ת��\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 500);
        set("attitude", "peaceful");

        setup();
        carry_object("d/taohua/obj/cloth")->wear();
}