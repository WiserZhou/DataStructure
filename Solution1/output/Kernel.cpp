#include "acl/acl.h"

// ���� SinhCustom �����ӵ�ʵ��
void SinhCustomKernel(const void *input, void *output) {
    // ע�⣺������Ҫʵ�� Sinh �㷨�ľ�������߼�
    // ����ʹ�� aclnn �� exp �� sinh �Ⱥ���

    // ʾ�����룬ʵ����Ҫ�滻Ϊʵ�ʵļ����߼�
    float16_t inputValue = *(float16_t *)input;
    float16_t result = sinh(inputValue);

    *(float16_t *)output = result;
}

// SinhCustom ������ע�ắ��
extern "C" {
aclError RegisterSinhCustomKernel() {
    aclError ret = aclRegisterOperatorKernel("SinhCustom", "SinhCustom", SinhCustomKernel);
    return ret;
}
}