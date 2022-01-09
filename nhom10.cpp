/*
Nhom 10
bai 13 */
#include <iostream>
using namespace std;
#include <string>
#include <fstream>

struct PHANXUONG
{
    string MaPX;
    string TenPX;
    int SoNV;
    string TruongPX;
};
struct Node {
    PHANXUONG* PX;
    struct Node* pHead;
};

typedef struct Node NODE;

void KhoiTao(Node*& list)
{
    list = new Node;
    list->pHead = NULL;
}

PHANXUONG* NhapPX()
{
    PHANXUONG* px = new PHANXUONG;
    cout << "Nhap ma phan xuong: ";
    getline(cin, px->MaPX);
    cout << "Nhap ten phan xuong: ";
    getline(cin, px->TenPX);
    cout << "Nhap so nhan vien: ";
    cin >> px->SoNV;
    cin.ignore(1);
    cout << "Nhap truong phan xuong: ";
    getline(cin, px->TruongPX);
    return px;
}

NODE* TaoMoiNode(PHANXUONG* data)
{
    NODE* newNode = new NODE;
    if (newNode != NULL)
    {
        newNode->PX = data;
        newNode->pHead = NULL;
    }
    return newNode;
}
NODE* TaoMoi(PHANXUONG* data)
{
    NODE* newN = new NODE;
    return newN;
}
NODE* Xuat(NODE* tail)
{
    NODE* current = tail->pHead;
    if (current == NULL)
    {
        cout << "Danh sach rong!\n";
        return tail;
    }
    while (current != NULL)
    {
        cout << "\nMa phan xuong: " << current->PX->MaPX << "\n";
        cout << "ten phan xuong: " << current->PX->TenPX << "\n";
        cout << "So nhan vien: " << current->PX->SoNV << "\n";
        cout << "Truong phan xuong: " << current->PX->TruongPX << "\n";
        current = current->pHead;
    }
    return tail;
}

NODE* ThemVaoDau(NODE* tail, PHANXUONG* data)
{
    NODE* current = tail->pHead;
    while (current != NULL)
    {
        PHANXUONG* px = current->PX;
        if (px->MaPX == data->MaPX)
        {
            cout << "=====> Phan xuong nay da ton tai !!! <=====" << "\n";
            return current;
        }
        current = current->pHead;
    }
    NODE* newNode = TaoMoiNode(data);
    if (tail == NULL) {
        tail = newNode;
        newNode->pHead = newNode;
    }
    else {
        newNode->pHead = tail->pHead;
        tail->pHead = newNode;
    }
    return tail;
}
NODE* ThemVaoCuoi(NODE* tail, PHANXUONG* data)
{
	
    NODE* current = tail->pHead;
    while (current != NULL)
    {
        PHANXUONG* px = current->PX;
        if (px->MaPX == data->MaPX)
        {
            cout << "=====> Phan xuong nay da ton tai !!! <=====" << "\n";
            return current;
        }
        current = current->pHead;
    }
    NODE* newNode = TaoMoi(data);
    if (tail == NULL) {
        tail = newNode;
        newNode->pHead = newNode;
    }
    else {
    
	newNode->pHead = tail->pHead;
	  tail=newNode;}
	  return tail;
}
NODE* XoaDau(NODE*& tail)
{
    Node* pDel = tail->pHead;
    if (pDel == NULL)
    {
        cout << "Danh sach rong!\n";
    }
    else
    {
        Node* pPre = NULL;
        if (pDel == NULL)
        {
            return tail;
        }
        else
        {
            if (pDel == tail->pHead)
            {
                tail->pHead = tail->pHead->pHead;
                pDel->pHead = NULL;
                delete pDel;
                pDel = NULL;
            }
            else
            {
                pPre->pHead = pDel->pHead;
                pDel->pHead = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
    return tail;
}

NODE* XoaPXVoiMa(NODE*& tail, string ma)
{
    Node* pDel = tail->pHead;
    if (pDel == NULL)
    {
        cout << "Danh sach rong!\n";
    }
    else
    {
        Node* pPre = NULL;
        while (pDel != NULL)
        {
            PHANXUONG* px = pDel->PX;
            if (px->MaPX == ma)
                break;
            pPre = pDel;
            pDel = pDel->pHead;
        }
        if (pDel == NULL)
        {
            cout << "Khong tim thay Ma phan xuong!!!\n" << ma;
        }
        else
        {
            if (pDel == tail->pHead)
            {
                tail->pHead = tail->pHead->pHead;
                pDel->pHead = NULL;
                delete pDel;
                pDel = NULL;
            }
            else
            {
                pPre->pHead = pDel->pHead;
                pDel->pHead = NULL;
                delete pDel;
                pDel = NULL;
            }
        }
    }
    return tail;
}

NODE* HuyToanBoNode(NODE*& tail, int n)
{
    for (int i = 0; i < n; i++)
    {
        Node* pDel = tail->pHead;
        if (pDel == NULL)
        {
            cout << "Danh sach rong!\n";
        }
        else
        {
            Node* pPre = NULL;
            if (pDel == NULL)
            {
                return tail;
            }
            else
            {
                if (pDel == tail->pHead)
                {
                    tail->pHead = tail->pHead->pHead;
                    pDel->pHead = NULL;
                    delete pDel;
                    pDel = NULL;
                }
                else
                {
                    pPre->pHead = pDel->pHead;
                    pDel->pHead = NULL;
                    delete pDel;
                    pDel = NULL;
                }
            }
        }
    }
    return tail;
}

NODE* TimPXVoiSoNV(NODE* tail, int sonv)
{
    NODE* current = tail->pHead;
    if (current == NULL)
    {
        cout << "Danh sach rong!\n";
        return tail;
    }
    while (current != NULL)
    {
        PHANXUONG* px = current->PX;
        if (px->SoNV > sonv)
        {
            cout << "\nMa phan xuong: " << current->PX->MaPX << "\n";
            cout << "Ten phan xuong: " << current->PX->TenPX << "\n";
            cout << "So nhan vien: " << current->PX->SoNV << "\n";
            cout << "Truong phan xuong: " << current->PX->TruongPX << "\n";
        }
        current = current->pHead;
    }
    return tail;
}

NODE* TimPXMaPX(NODE* tail, string ma)
{
    NODE* current = tail->pHead;
    if (current == NULL)
    {
        cout << "Danh sach rong!\n";
        return tail;
    }
    while (current != NULL)
    {
        PHANXUONG* px = current->PX;
        if (px->MaPX == ma)
        {
            cout << "\nMa phan xuong: " << current->PX->MaPX << "\n";
            cout << "Ten phan xuong: " << current->PX->TenPX << "\n";
            cout << "So nhan vien: " << current->PX->SoNV << "\n";
            cout << "Truong phan xuong: " << current->PX->TruongPX << "\n";
        }
        current = current->pHead;
    }
    return tail;
}


int DemPXVoiSoNV(NODE* tail, int sonv)
{
    int dem = 0;
    NODE* current = tail->pHead;
    if (current == NULL)
    {
        cout << "Danh sach rong!\n";
        return 0;
    }
    while (current != NULL)
    {
        PHANXUONG* px = current->PX;
        if (px->SoNV < sonv)
            dem++;
        current = current->pHead;
    }
    return dem;
}

NODE* SapXepTangDanSoNV(NODE*& tail)
{
    for (Node* current = tail->pHead; current != NULL; current = current->pHead)
    {
        for (Node* current2 = current->pHead; current2 != NULL; current2 = current2->pHead)
        {
            PHANXUONG* px1 = current->PX;
            PHANXUONG* px2 = current2->PX;
            if (px1->SoNV > px2->SoNV)
            {
                string mapx = px1->MaPX;
                string tenpx = px1->TenPX;
                int sonv = px1->SoNV;
                string truongpx = px1->TruongPX;
                px1->MaPX = px2->MaPX;
                px1->TenPX = px2->TenPX;
                px1->SoNV = px2->SoNV;
                px1->TruongPX = px2->TruongPX;
                px2->MaPX = mapx;
                px2->TenPX = tenpx;
                px2->SoNV = sonv;
                px2->TruongPX = truongpx;
            }
        }
    }
    return tail;
}

NODE* ThemVao1ViTri(NODE* tail, PHANXUONG* px, int n, int location) {
    int len = n, i;
    if (location < 1 || location > len + 1) {
        cout<<"vi tri hop le de nhap du lieu";
    }
    else {
        if (tail == NULL) return ThemVaoDau(tail, px);
        NODE* newNode = TaoMoiNode(px), * current = tail;
        for (i = 1; i != location; i++) current = current->pHead;
        newNode->pHead = current->pHead;
        current->pHead = newNode;
        if (location == len + 1) tail = newNode;
    }
    return tail;
}

int TimViTriCanThem(NODE* tail, PHANXUONG* px)
{
    int i = 0;
    for (Node* current = tail->pHead; current != NULL; current = current->pHead)
    {
        i++;
        PHANXUONG* px1 = current->PX;
        if (current->pHead != NULL)
        {
            PHANXUONG* px2 = current->pHead->PX;
            if (px1->SoNV <= px->SoNV && px2->SoNV >= px->SoNV)
            {
                return i + 1;
            }
        }
    }
}

NODE* TimKiemPXTheoSoNV(NODE* tail, int sonv)
{
    NODE* current = tail->pHead;
    if (current == NULL)
    {
        cout << "Danh sach rong!\n";
        return tail;
    }
    while (current != NULL)
    {
        PHANXUONG* px = current->PX;
        if (px->SoNV >= sonv)
        {
            cout << "\nMa phan xuong: " << current->PX->MaPX << "\n";
            cout << "Ten phan xuong: " << current->PX->TenPX << "\n";
            cout << "So nhan vien: " << current->PX->SoNV << "\n";
            cout << "Truong phan xuong: " << current->PX->TruongPX << "\n";
        }
        current = current->pHead;
    }
    return tail;
}

void ThemVaoNodeDanhSachSapXepTang(NODE* list, PHANXUONG* px, int n)
{
    SapXepTangDanSoNV(list);
    int i = TimViTriCanThem(list, px);
    ThemVao1ViTri(list, px, n, i);
}

int main()
{
    NODE* list;
    KhoiTao(list);
    int n;
    cout << "Nhap so luong phan xuong: ";
    cin >> n;
    cin.ignore(1);
    for (int i = 0; i < n; i++)
    {
        PHANXUONG* a = NhapPX();
        
        ThemVaoDau(list, a);
    }
    int luachon;
    do
    {
        cout << "Lua chon chuc nang: \n";
        cout << "1. Hien thi toan bo danh sach\n";
        cout << "2. Tim mot phan xuong theo ma phan xuong\n";
        cout << "3. Them mot phan xuong vao cuoi danh sach\n";
        cout << "4. Xoa mot phan xuong theo ma phan xuong\n";
        cout << "5. Hien thi danh sach theo so nhan vien\n";
        cout << "6. Dem so phan xuong duoi 10 nhan vien\n";
        cout << "7. Sap xep danh sach tang dan so nhan vien\n";
        cout << "8. Them mot phan xuong vao danh sach sap xep tang theo so nhan vien\n";
        cout << "9. Tim kiem danh sach phan xuong co so nhan vien >= 15\n";
        cout << "10. Huy toan bo danh sach\n";
        cout << "0. Thoat chuong trinh\n";
        cin >> luachon;
        cin.ignore(1);
        if (luachon == 1)
        {
            Xuat(list);
        }
        else if (luachon == 2)
        {
            string ma;
            cout << "Nhap vao ma muon tim: ";
            getline(cin, ma);
            TimPXMaPX(list, ma);
        }
        else if (luachon == 3)
        {
            PHANXUONG* a = NhapPX();
            ThemVaoCuoi(list, a);
            n++;
        }
        else if (luachon == 4)
        {
            string ma;
            cout << "Nhap vao ma muon xoa: ";
            getline(cin, ma);
            XoaPXVoiMa(list, ma);
            n--;
        }
        else if (luachon == 5)
        {
            int sonv;
            cout << "Nhap vao so nhan vien muon tim: ";
            cin >> sonv;
            cin.ignore(1);
            TimPXVoiSoNV(list, sonv);
        }
        else if (luachon == 6)
        {
            int sonv = 10;
            cout << "So phan xuong duoi 10 nhan vien: " << DemPXVoiSoNV(list, sonv) << "\n";
        }
        else if (luachon == 7)
        {
            SapXepTangDanSoNV(list);
            Xuat(list);
        }
        else if (luachon == 8)
        {
            PHANXUONG* a = NhapPX();
            ThemVaoNodeDanhSachSapXepTang(list, a, n);
            n++;
            Xuat(list);
        }
        else if (luachon == 9)
        {
            TimKiemPXTheoSoNV(list, 15);
        }
        else if (luachon == 10)
        {
            HuyToanBoNode(list, n);
        }
        else if (luachon == 0)
        {
            break;
        }
        else
            cout << "Chuc nang nay khong ton tai!!!\n";
    } while (luachon < 10 || luachon > 0);
}