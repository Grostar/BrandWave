/**
 * BrandWave - Main Script
 * Professionalized structure with modular initialization.
 */

// Forzar que la página cargue siempre desde arriba del todo
if ('scrollRestoration' in history) {
  history.scrollRestoration = 'manual';
}

window.addEventListener('load', () => {
  setTimeout(() => {
    window.scrollTo(0, 0);
  }, 10);
});

// Global functions for inline HTML event handlers
window.toggleMenu = function () {
  const navLinks = document.getElementById('navLinks');
  if (navLinks) navLinks.classList.toggle('active');
};

window.scrollToTop = function () {
  const duration = 1500;
  const start = window.scrollY;
  const startTime = performance.now();

  function animateScroll(currentTime) {
    const elapsed = currentTime - startTime;
    const progress = Math.min(elapsed / duration, 1);
    const easing = 1 - Math.pow(1 - progress, 3); // Cubic ease out

    window.scrollTo(0, start * (1 - easing));

    if (progress < 1) {
      requestAnimationFrame(animateScroll);
    }
  }
  requestAnimationFrame(animateScroll);
};

window.scrollToContact = function () {
  const contactSection = document.getElementById('contact');
  if (contactSection) {
    contactSection.scrollIntoView({ behavior: 'smooth' });
  }
};

// --- Main Initialization ---
document.addEventListener('DOMContentLoaded', () => {
  initNavigation();
  initScrollEffects();
  initParticles();
  initMobileHoverSim();
});

// --- 1. Navegación y Menú ---
function initNavigation() {
  const navLinks = document.getElementById('navLinks');
  const hamburger = document.querySelector('.hamburger');

  if (!navLinks || !hamburger) return;

  // Cerrar menú al hacer clic fuera
  document.addEventListener('click', (event) => {
    const clickedInsideMenu = navLinks.contains(event.target);
    const clickedHamburger = hamburger.contains(event.target);

    if (!clickedInsideMenu && !clickedHamburger) {
      navLinks.classList.remove('active');
    }
  });

  // Cerrar menú al hacer clic en cualquier enlace interno
  const links = navLinks.querySelectorAll('a');
  links.forEach(link => {
    link.addEventListener('click', () => {
      navLinks.classList.remove('active');
    });
  });

  // Cerrar menú al hacer scroll manual
  window.addEventListener('scroll', () => {
    if (navLinks.classList.contains('active')) {
      navLinks.classList.remove('active');
    }
  }, { passive: true });
}

// --- 2. Efectos de Scroll (Fade In y Botones) ---
function initScrollEffects() {
  // Intersection Observer para fade-in
  const observerOptions = {
    threshold: 0.15,
    rootMargin: "0px 0px -50px 0px"
  };

  const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {
      if (entry.isIntersecting) {
        entry.target.classList.add('visible');
      }
    });
  }, observerOptions);

  document.querySelectorAll('.fade-in').forEach(element => {
    observer.observe(element);
  });

  // Botón scroll top
  const scrollBtn = document.getElementById('scrollTopBtn');
  if (scrollBtn) {
    window.addEventListener('scroll', () => {
      scrollBtn.style.display = window.scrollY > 300 ? 'block' : 'none';
    }, { passive: true });
  }
}

// --- 3. Efectos Hover Simulados en Móviles ---
function initMobileHoverSim() {
  const hoverElements = document.querySelectorAll('.namebrand, .nav-links a, .hero-content button, .services-image img, .ofrecemos-img img, .logo-item, .social-icons a');

  if (hoverElements.length === 0) return;

  // Efecto al tocar
  hoverElements.forEach(el => {
    el.addEventListener('touchstart', () => {
      if (window.innerWidth <= 768) {
        el.classList.add('simulated-hover');
      }
    }, { passive: true });

    el.addEventListener('touchend', () => {
      setTimeout(() => el.classList.remove('simulated-hover'), 500);
    }, { passive: true });
  });

  const brandwaveElements = Array.from(hoverElements).filter(el => el.classList.contains('namebrand'));
  const socialElements = Array.from(hoverElements).filter(el => el.closest('.social-icons'));
  const otherElements = Array.from(hoverElements).filter(el => !el.classList.contains('namebrand') && !el.closest('.social-icons'));

  function triggerHover(elements, staggerMs = 0) {
    if (window.innerWidth <= 768) {
      elements.forEach((el, index) => {
        const rect = el.getBoundingClientRect();
        const isVisible = (
          rect.top >= 0 &&
          rect.left >= 0 &&
          rect.bottom <= (window.innerHeight || document.documentElement.clientHeight) &&
          rect.right <= (window.innerWidth || document.documentElement.clientWidth)
        );

        if (isVisible) {
          setTimeout(() => {
            el.classList.add('simulated-hover');
            setTimeout(() => {
              el.classList.remove('simulated-hover');
            }, 1500);
          }, index * staggerMs);
        }
      });
    }
  }

  // Efecto automático para Brandwave cada 3 segundos
  setInterval(() => triggerHover(brandwaveElements), 3000);

  // Efecto ola para iconos sociales cada 6 segundos (300ms de diferencia entre cada uno)
  setInterval(() => triggerHover(socialElements, 300), 6000);

  // Efecto automático para el resto de elementos cada 6 segundos
  setInterval(() => triggerHover(otherElements), 6000);
}

// --- 4. Configuración de Partículas ---
function initParticles() {
  if (typeof particlesJS !== 'undefined') {
    const isMobile = window.innerWidth < 768;
    particlesJS({
      "particles": {
        "number": { "value": isMobile ? 180 : 150, "density": { "enable": true, "value_area": 800 } },
        "color": { "value": "#ffffff" },
        "shape": {
          "type": "circle",
          "stroke": { "width": 0, "color": "#000000" },
          "polygon": { "nb_sides": 5 }
        },
        "opacity": { 
          "value": 0.6, 
          "random": isMobile, 
          "anim": { "enable": isMobile, "speed": 1.5, "opacity_min": 0.1, "sync": false } 
        },
        "size": { 
          "value": isMobile ? 4 : 3, 
          "random": true, 
          "anim": { "enable": false, "speed": 40, "size_min": 0.1, "sync": false } 
        },
        "line_linked": { "enable": !isMobile, "distance": 150, "color": "#ffffff", "opacity": 0.4, "width": 1 },
        "move": {
          "enable": true, 
          "speed": isMobile ? 1 : 2, 
          "direction": "none", 
          "random": true, 
          "straight": false,
          "out_mode": "bounce", 
          "bounce": false, 
          "attract": { "enable": false, "rotateX": 600, "rotateY": 1200 }
        }
      },
      "interactivity": {
        "detect_on": "canvas",
        "events": {
          "onhover": { "enable": !isMobile, "mode": "grab" },
          "onclick": { "enable": true, "mode": isMobile ? "repulse" : "push" },
          "resize": true
        },
        "modes": {
          "grab": { "distance": 150, "line_linked": { "opacity": 1 } },
          "bubble": { "distance": 200, "size": 5, "duration": 2, "opacity": 8, "speed": 3 },
          "repulse": { "distance": 100, "duration": 0.4 },
          "push": { "particles_nb": 4 },
          "remove": { "particles_nb": 2 }
        }
      },
      "retina_detect": true
    });
  }
}
// --- 5. L�gica del Cookie Banner ---
document.addEventListener('DOMContentLoaded', () => {
  const cookieBanner = document.getElementById('cookieBanner');
  if (cookieBanner && !localStorage.getItem('cookiesAccepted')) {
    setTimeout(() => {
      cookieBanner.style.display = 'flex';
    }, 1000);
  }
});

window.acceptCookies = function() {
  localStorage.setItem('cookiesAccepted', 'true');
  const cookieBanner = document.getElementById('cookieBanner');
  if (cookieBanner) cookieBanner.style.display = 'none';
};
