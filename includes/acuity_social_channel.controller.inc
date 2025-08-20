<?php
/**
 * @file
 * Defines the AcuitySocialChannelController entity controller class.
 */

// Extend Backdrop's standard UI controller for entities.
class AcuitySocialChannelController extends EntityDefaultUIController {

  /**
   * Overrides EntityDefaultUIController::uri().
   *
   * Provides the standard path for a channel entity.
   */
  public function uri() {
    return ['path' => 'social-channel/' . $this->id()];
  }

  // You can add other overrides here later.
}