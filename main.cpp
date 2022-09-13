
#include<iostream>
#include<graphics.h>
#include <windows.h>
#include<sstream>
using namespace std; 


class Graphics {
	private: 
		/* STATE */
		int widhScreen , heightScreen; 
		/* METHOD */
		void getMaxScreen () {
			this->widhScreen = GetSystemMetrics(SM_CXSCREEN); 
			this->heightScreen = GetSystemMetrics(SM_CYSCREEN); 
	}
	public:
		Graphics () {
			this->getMaxScreen(); 
		}
		Graphics (int widhScreen,int heightScreen) {
			this->widhScreen = widhScreen; 
			this->heightScreen = heightScreen; 
		}
		void init () {
			initwindow(this->widhScreen, this->heightScreen);
		}	
        static void drawRegtagle (int x,int y,int w,int h) {
        	bar(x,y, x+w,y + h); 
		}
		
		
};



class Helper{
	public : 
	static void sapXepTangDan(int *arr,int soLuongPhanTu) {
	for (int i = 0; i < soLuongPhanTu - 1;i++) {
		for (int j = i + 1;j < soLuongPhanTu;j++) {
			if (arr[i] > arr[j]) {
				hoanDoiSoNguyen(arr[i],arr[j]); 
			}
			
		}
	}
}
	static void sapXepGiamDan(int *arr,int soLuongPhanTu) {
	for (int i = 0; i < soLuongPhanTu - 1;i++) {
		for (int j = i + 1;j < soLuongPhanTu;j++) {
			if (arr[i] < arr[j]) {
				hoanDoiSoNguyen(arr[i],arr[j]); 
			}
			
		}
	}
}
	static void hoanDoiSoNguyen(int &soNguyen1,int &soNguyen2) {
		int intTemp =soNguyen1;
		soNguyen1 = soNguyen2;
		soNguyen2 = intTemp;
	}
	static int soPhanTuKhacKhong(int *arr,int n) 
	{
		int soPhanTuKhac0 = 0; 
		for (int i = 0; i < n;i++) {
			if (arr[i] != 0) {
				soPhanTuKhac0++; 
			}
		}
		return soPhanTuKhac0; 
	}
};

class Tower {
	private : 
		int soDia; 
		int *diaCotA,*diaCotB,*diaCotC;  // chua so dia.
		int A,C;  // su dung cho muc dich danh dau, 
		int tocDo; 
		
		// BIEN SU DUNG CHUNG CHO CA CLASS...
		int canLeXGiaDo , khoanCachGiaDo ,chieuDaiGiaDo , chieuCaoGiaDo , toaDoYGiaDo , chieuDaiThanh , 
		toaDoXCotA , toaDoXCotB , toaDoXCotC,  chieuCaoDia, khoanCachDia; 
		


		void khoiTaoBanKinhDia () {  //  ham nay khong duoc ben ngoai nhin thay. 
			diaCotA = new int[this->soDia]; 
			diaCotB = new int[this->soDia]; 
			diaCotC = new int[this->soDia]; 

			const int chenhLechDuongKinh = 30;  
			int tempDuongKinhDia = 300; 
			
			for (int i = this->soDia - 1; i >= 0;i--) {
				diaCotA[i] = tempDuongKinhDia;   
				tempDuongKinhDia -=  chenhLechDuongKinh; 
				diaCotB[i] = diaCotC[i] = 0; // khong co dia nao !
			}
			
		
			
		}
	public: 
	Tower () {
			soDia = 0;
			
			// BIEN SU DUNG CHUNG
			
			canLeXGiaDo = 40;  
			khoanCachGiaDo = 100;  
			chieuDaiGiaDo = 300; 
			chieuCaoGiaDo = 16; 
			toaDoYGiaDo = 700;
			chieuDaiThanh = 18; 
			chieuCaoDia = 18; 
			khoanCachDia = 6; 
			
			tocDo = 8; 
			// toa do 3 cot ( sau khi tinh toan )
			toaDoXCotA = canLeXGiaDo  +  chieuDaiGiaDo / 2 - chieuDaiThanh  / 2; 
			toaDoXCotB = khoanCachGiaDo + chieuDaiGiaDo + canLeXGiaDo + chieuDaiGiaDo / 2 - chieuDaiThanh / 2;
			toaDoXCotC =  (khoanCachGiaDo + chieuDaiGiaDo)*2 + canLeXGiaDo + chieuDaiGiaDo / 2 - chieuDaiThanh / 2;
			
			
			
		}
		void thapHaNoi (int soDiaParam,int *diaCotA,int toaDoXCotA,int *diaCotB,int toaDoXCotB,
		int *diaCotC, int toaDoXCotC,string strA,string strB,string strC) {
			if (soDiaParam == 1) {
				cout << strA << " ---> " << strC << endl; 
				Helper::sapXepTangDan(diaCotA,this->soDia);
				Helper::sapXepGiamDan(diaCotC,this->soDia); 
				for (int i = 0; i < this->soDia;i++) {
					if (diaCotA[i] != 0) {
						this->A = i; 
						break; 
					}
					this->A = 0; 
				}
				for (int i = 0; i < this->soDia;i++) {
					if (diaCotC[i] != 0) {
						this->C = i; 
						break;
					}
					this->C= 0; 
				}
				// lay ra so luong phan tu khac 0 
				int soDiaCotA = Helper::soPhanTuKhacKhong(diaCotA,this->soDia); 
				int soDiaCotC = Helper::soPhanTuKhacKhong(diaCotC,this->soDia); 
				
				
				this->diChuyenDia(toaDoXCotA,soDiaCotA,toaDoXCotC,soDiaCotC,diaCotA[A]);
				 for (int i = C; i < this->soDia;i++) {
					if (diaCotC[i] == 0) {
						Helper::hoanDoiSoNguyen(diaCotA[A],diaCotC[i]); 
						break; 
					}
				 }
				 diaCotA[A] = 0; 
			}
			else {
				thapHaNoi(soDiaParam - 1,diaCotA,toaDoXCotA,diaCotC,toaDoXCotC,diaCotB,toaDoXCotB,"Cot A","Cot C","Cot B"); 
				thapHaNoi(1,diaCotA,toaDoXCotA,diaCotB,toaDoXCotB,diaCotC,toaDoXCotC,"Cot A","Cot B","Cot C");
				thapHaNoi(soDiaParam - 1,diaCotB,toaDoXCotB,diaCotA,toaDoXCotA,diaCotC,toaDoXCotC,"Cot B","Cot A","Cot C"); 
			}
	}
		// LAM VIEC CHINH 
		void diChuyenDia (int XcotDau,int soDiaCotDau,int XcotSau,int soDiaCotSau,int duongKinhDiaTrenCung) {
			int XDiaCotDau = XcotDau  - duongKinhDiaTrenCung / 2 + 18 / 2  ;  
			int i; 
			for (i = 0; i <= (480 - chieuCaoDia * soDiaCotDau) ; i += tocDo ) {  // ve di xoa lai 400 lan. 
				this->veDia( XDiaCotDau, toaDoYGiaDo - i  - (chieuCaoDia + khoanCachDia) * soDiaCotDau,duongKinhDiaTrenCung ); 
				delay(0); 
				this->xoaDia( XDiaCotDau, toaDoYGiaDo - i  - (chieuCaoDia + khoanCachDia) * soDiaCotDau,duongKinhDiaTrenCung );
				this->ve03Cot(); 	
			} 
			
			int YDiaDiChuyenNgang = toaDoYGiaDo - i  - (chieuCaoDia + khoanCachDia) * soDiaCotDau; 
			int toaDoXDiaDiChuyen; 
			
			if (XcotDau - XcotSau < 0) {
				int SdiChuyenDia = XcotSau - XcotDau; 
		
				int j; 
				for (j = 0; j <= SdiChuyenDia ;j += tocDo) {
					this->veDia(XDiaCotDau + j ,YDiaDiChuyenNgang,duongKinhDiaTrenCung); 
					delay(0); 
					this->xoaDia(XDiaCotDau + j ,YDiaDiChuyenNgang,duongKinhDiaTrenCung);  
					this->ve03Cot(); 
					
				} 
				toaDoXDiaDiChuyen = XcotSau - duongKinhDiaTrenCung / 2 + 18 / 2; 
				
			}
			else {
				int SdiChuyenDia = XcotDau - XcotSau; 
				int j; 
				for (j = 0; j <= SdiChuyenDia;j+= tocDo) {
					this->veDia(XDiaCotDau - j ,YDiaDiChuyenNgang,duongKinhDiaTrenCung); 
					delay(0); 
					this->xoaDia(XDiaCotDau - j,YDiaDiChuyenNgang,duongKinhDiaTrenCung); 
					this->ve03Cot(); 
				}

				toaDoXDiaDiChuyen = XcotSau - duongKinhDiaTrenCung / 2 + 18 / 2; 
			}
		
			int YdiaTrenCungCotSau = toaDoYGiaDo - ( chieuCaoDia + khoanCachDia ) * soDiaCotSau - chieuDaiThanh - khoanCachDia;  
			
		  	int k; 
		  	int toaDoYDiaDuyChuyen = YDiaDiChuyenNgang; 
		  	
		  	for (k = toaDoYDiaDuyChuyen; k < YdiaTrenCungCotSau;k+= tocDo) {
		  		// tang dan k len 
		  		this->veDia(toaDoXDiaDiChuyen,k,duongKinhDiaTrenCung); 
		  		delay(0); 
		  		this->xoaDia(toaDoXDiaDiChuyen,k,duongKinhDiaTrenCung); 
		  		this->ve03Cot();   		
			  }
			  this->veDia(toaDoXDiaDiChuyen,k,duongKinhDiaTrenCung); 
	
		}
		
		void veDia (int X,int Y,int duongKinh) { 
			setfillstyle(SOLID_FILL, 14); 
			Graphics::drawRegtagle(X,Y,duongKinh,this->chieuCaoDia); 
		}
		
		
		void xoaDia (int X,int Y,int duongKinh) {
			setfillstyle(SOLID_FILL, 0);
			Graphics::drawRegtagle(X,Y,duongKinh,this->chieuCaoDia); 
		}
		
		void play () { 
			this->thapHaNoi(soDia,diaCotA,toaDoXCotA,diaCotB,toaDoXCotB,diaCotC,toaDoXCotC,"Cot A","Cot B","Cot C"); 
		}
		
		~Tower () {
			delete [] diaCotA; 
			delete [] diaCotB; 
			delete [] diaCotC; 
		}
	
		
		
		void veCot () {  //  ve ra 3 cay cot mac dinh. 
			Graphics::drawRegtagle(toaDoXCotA,toaDoYGiaDo + chieuDaiThanh,chieuDaiThanh,-400); 	
			Graphics::drawRegtagle(toaDoXCotB,toaDoYGiaDo + chieuDaiThanh,chieuDaiThanh,-400); 
			Graphics::drawRegtagle(toaDoXCotC,toaDoYGiaDo + chieuDaiThanh,chieuDaiThanh,-400); 
		}
		
		void veGiaDo () { 
			Graphics::drawRegtagle(canLeXGiaDo,toaDoYGiaDo,chieuDaiGiaDo,chieuDaiThanh); 
			Graphics::drawRegtagle(khoanCachGiaDo + chieuDaiGiaDo + canLeXGiaDo,toaDoYGiaDo,300,chieuDaiThanh);
			Graphics::drawRegtagle( (khoanCachGiaDo + chieuDaiGiaDo)*2 + canLeXGiaDo,toaDoYGiaDo,300,chieuDaiThanh);
		}
		
		void ve03Cot () {
			setfillstyle(SOLID_FILL, 2); 
			Graphics::drawRegtagle(toaDoXCotA,toaDoYGiaDo + chieuDaiThanh,chieuDaiThanh,-400); 	
			Graphics::drawRegtagle(toaDoXCotB,toaDoYGiaDo + chieuDaiThanh,chieuDaiThanh,-400); 
			Graphics::drawRegtagle(toaDoXCotC,toaDoYGiaDo + chieuDaiThanh,chieuDaiThanh,-400); 
		}
			
		void khoiTaoGiaoDien() {
			setfillstyle(SOLID_FILL, 2);   
			this->veGiaDo();  		
			this->ve03Cot(); 
			this->khoiTaoBanKinhDia(); 
			this->veNhieuDia(this->diaCotA,canLeXGiaDo,toaDoYGiaDo); 
		}

		void veNhieuDia (int *diaCotX,int toaDoX,int toaDoY) {  // viet lai thanh ham ve dia cua cot
			int temp = this->soDia; 
			const int mauDia = 14; 
			setfillstyle(SOLID_FILL, mauDia);
		
			for (int i = 0; i < this->soDia;i++) {
				int toaDoXDiaCon = toaDoX + 300  /  2 - diaCotA[i] / 2; 
				Graphics::drawRegtagle(toaDoXDiaCon, toaDoY - temp * (chieuCaoDia + khoanCachDia)  ,this->diaCotA[i],chieuCaoDia); 
				temp--; 
			}
		}
		
		int chonSoDia () {
			char c; 
			string inputNumberDict; 
			const int ENTER = 13; // nguoi dung lua chon so. 
			const int BACK_SPACE = 8; 
			settextstyle(10, 0, 4);
			outtextxy(32,32,(char*)"Nhap vao so luong dia: ");
			while (true) { 
				outtextxy(460,32,(char*)inputNumberDict.c_str()); 
				c = getch();
				if (  c >= 48 && c <= 57) { 
					inputNumberDict += c; //  kiem tra do dai  
				}
				if ( c == ENTER ) { 
					stringstream ss;
					ss <<  inputNumberDict;
					ss >> this->soDia; 
					setfillstyle(SOLID_FILL, 0);
					bar(0, 0, 2000, 2000);
					break; 
				}
				
			}
			return this->soDia;  	
		}	
};


int main () {
	Graphics screen; 
	screen.init(); // khoi tao man hinh do hoa. 
	Tower tower;  
	int soDia = tower.chonSoDia();  
	tower.khoiTaoGiaoDien(); 
	tower.play(); 
	getch(); 	
	return 0; 
	
}
